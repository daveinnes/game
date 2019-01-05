#include "building.h"

#include <cmath>

#include "tuning.h"
#include "render.h"

Building::Building(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Unit(pos, dimensions, tuning, c) {
    updateDamage();
}

Building::~Building() {
}

void Building::createBehavior() {
}

void Building::updateDamage() {
    mSectionsAlive = std::ceil(percentHealth() * mDimensions.x * mDimensions.y);
}

void Building::attack(Unit* target) {
}

void Building::receiveAttack(Unit* source) {
    Unit::receiveAttack(source);
    updateDamage();
}

void Building::die() {
    Unit::die();
}

bool Building::canBuild() {
    return !mBuilding && !mBuilt && Buildable::canBuild();
}

void Building::update() {
    Unit::update();
}

void Building::render(Render* render) {
    if(mBuilt || mBuilding) {
        if(mBuilding) {
            render->fillBlinkAt(mPos.x, mPos.y, mDimensions.x, mDimensions.y, mBuilding);
        }
        for(int x = 0; x < mDimensions.x; ++x) {
            for(int y = 0; y < mDimensions.y; ++y) {
                int index = y * mDimensions.x + x;
                if(index < mSectionsAlive) {
                    render->put(mPos.x+x, mPos.y+y, mChar, mColour);
                }
            }
        }
    }
}