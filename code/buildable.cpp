#include "buildable.h"
#include "player.h"
#include "assert.h"
#include "resource.h"
#include "tuning.h"
#include "time_manager.h"
#include "game.h"
#include "vector.h"

Buildable::Buildable(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Object(pos, dimensions, c)
, mCost(tuning["cost"]) 
, mBuilt(false)
, mBuilding(false)  
, mBuildTime(tuning["buildTime"].asFloat())
, mSupplyCost(tuning["supplyCost"].asInt()) {

}

Buildable::~Buildable() {

}

bool Buildable::canBuild() {
    bool canBuild = mPlayer->bank()->money >= mCost.money
                    && mPlayer->bank()->research >= mCost.research
                    && mPlayer->availableSupply() >= mSupplyCost;
    return canBuild;
}

void Buildable::subtractCost() {
    Resource& bank = *mPlayer->bank();
    bank -= mCost;
}

void Buildable::addSupply() {
    mPlayer->usedSupply() += mSupplyCost;
}

void Buildable::removeSupply() {
    mPlayer->usedSupply() -= mSupplyCost;
}

void Buildable::startBuild() {
    bool can = canBuild();
    ASSERT(can);
    subtractCost();
    addSupply();
    mBuildStartTime = Game::get()->time()->get();
    mBuilding = true;
}

void Buildable::startBuildNoCost() {
    mBuildStartTime = Game::get()->time()->get();
    mBuilding = true;
}

void Buildable::finishBuild() {
    mBuilt = true;
    mBuilding = false;
}

void Buildable::update() {
    if(mBuilding) {
        float time = Game::get()->time()->get();
        if(time - mBuildStartTime >= mBuildTime) {
            finishBuild();
        }
    }
    Object::update();
}
