#include "unitbehavior.h"
#include "unit.h"
#include "game.h"
#include "time.h"
#include "world.h"
#include "player.h"
#include "object.h"

UnitBehavior::UnitBehavior(Unit* unit)
: mUnit(unit) {
    mStartingX = mUnit->mPos.xInt();
}

void UnitBehavior::update() {
    Unit* target = pickTarget();
    if(target != nullptr) {
        mUnit->attack(target);
    } else {
        move();
    }
}

Unit* UnitBehavior::pickTarget() {
    World* world = Game::get()->world();
    for(int i = 0; i < 3; ++i) {
        mAdjacentPos[i] = mUnit->mPos;
        mAdjacentPos[i].y += mUnit->side();
    }
    mAdjacentPos[0].x -= 1;
    mAdjacentPos[2].x += 1;

    Unit* target = nullptr;
    for(int i = 0; i < 3; ++i) {
        Object* objAt = mAdjacentObjects[i] = world->at(mAdjacentPos[i]);
        if(objAt != nullptr) {
            Unit* potentialTarget = objAt->as<Unit>();
            if(potentialTarget != nullptr 
                && !potentialTarget->isDead() 
                && potentialTarget->side() != mUnit->side()) {
                if(target ==  nullptr || potentialTarget->mHealth < target->mHealth) {
                    target = potentialTarget;
                }
            }
        }
    }
    return target;
}


void UnitBehavior::move() {
    float deltaTime = Game::get()->time()->delta();
    Vector2 direction;
    if(mAdjacentObjects[1] == nullptr) {
        direction.y += mUnit->side();
    } else {
        if(mAdjacentObjects[0] == nullptr && mAdjacentPos[0].xInt() >= mStartingX - 1) {
            direction.x -= 1;
        } else {
            if(mAdjacentObjects[2] == nullptr && mAdjacentPos[2].xInt() <= mStartingX + 1) {
                direction.x += 1;
            } else {
                if(mUnit->pos().xInt() > mStartingX) {
                    direction.x -= 1;
                } else if(mUnit->pos().xInt() < mStartingX) {
                    direction.x += 1;
                }
            }
        }
    }

    World* world = Game::get()->world();
    Vector2 targetPos = mUnit->mPos + direction;
    if(world->at(targetPos) == nullptr && world->isInBounds(targetPos)) {
        mUnit->mPos += direction * mUnit->mSpeed * deltaTime;
    }
}