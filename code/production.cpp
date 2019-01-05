#include "production.h"

#include <algorithm>
#include <cmath>

#include "tuning.h"
#include "render.h"
#include "objectfactory.h"
#include "unit.h"
#include "game.h"
#include "world.h"
#include "player.h"

Production::Production(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Building(pos, dimensions, tuning, c)
, mPendingUnit(nullptr) {
}

Production::~Production() {
    delete mPendingUnit;
    for(Unit* unit : mUnits) {
        delete unit;
    }
}
void Production::calculateSpawnPos() {
    int side = mPlayer->side();
    int yOffset = side == 1 ? mDimensions.y : -1;
    mSpawnPos.x = mPos.x + std::floor(mDimensions.x / 2);
    mSpawnPos.y = mPos.y + yOffset;
}

void Production::finishBuild() {
    Building::finishBuild();
    calculateSpawnPos();
}

bool Production::canBuildUnit() {
    if(mPendingUnit == nullptr) {
        mPendingUnit = ObjectFactory::newObject<Unit>(mSpawnPos, Vector2(1,1));
        mPendingUnit->player() = mPlayer;
    }
    return mPendingUnit->canBuild();
}

bool Production::canSpawn() {
    return Game::get()->world()->at(mSpawnPos) == nullptr;
}

bool Production::full() {
    return mUnits.size() >= mSectionsAlive;
}

void Production::buildUnit(char c) {
    if(mBuilt && !full() && canBuildUnit()) {
        mPendingUnit->subtractCost();
        mPendingUnit->addSupply();
        mUnits.push_back(mPendingUnit);
        mPendingUnit = nullptr;
    }
}

void Production::spawn(Unit* unit) {
    mUnits.erase(std::find(mUnits.begin(), mUnits.end(), unit));
    Game::get()->world()->add(unit);
    unit->spawned() = true;
}

void Production::update() {
    if(mUnits.size() > 0) {
        Unit* unit = mUnits[0];
        if(!unit->isBuilding()) {
            unit->startBuildNoCost();
        }
        unit->update();
        if(unit->isBuilt()) {
            if(canSpawn()) {
                spawn(unit);
            } else {
                Object* objAtSpawn = Game::get()->world()->at(mSpawnPos);
                if(objAtSpawn != nullptr) {
                    Unit* blockingUnit = objAtSpawn->as<Unit>();
                    if(blockingUnit != nullptr) {
                        unit->attack(blockingUnit);
                    }
                }
            }
        }
    }
    Buildable::update();
}

void Production::render(Render* r) {
    if(mBuilt) {
        int buildingCount = mUnits.size();
        for(int y = 0; y < mDimensions.y; ++y) {
            for(int x = 0; x < mDimensions.x; ++x) {
                int index = y * mDimensions.x + x;
                bool renderChar = false;
                if(true || side() > 0) {
                    renderChar = index < mSectionsAlive;
                } else {
                    renderChar = index >= ( mDimensions.x * mDimensions.y - mSectionsAlive );
                }
                if(renderChar) {
                    Vector2 offset(x, y);
                    Vector2 pos = mPos + offset;
                    char c = mChar;
                    if(buildingCount > 0){
                        c = mUnits[0]->renderChar();
                        bool blink = buildingCount != mUnits.size() || !mUnits[0]->isBuilt();
                        if(blink) {
                            r->blinkAt(pos.x, pos.y) = true;
                        }
                        --buildingCount;
                    }
                    r->put(pos, c, mColour);
                }
            }
        }
    } else {
        Building::render(r);
    }
}
