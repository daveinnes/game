#include "unitbehavior.h"
#include "unit.h"
#include "game.h"
#include "time_manager.h"
#include "world.h"
#include "player.h"
#include "object.h"
#include "pathfinding.h"
#include "waypoint.h"

UnitBehavior::UnitBehavior(Unit* unit)
: mUnit(unit)
, mWaypoint(nullptr) {
    mStartingX = mUnit->mPos.xInt();
}

void UnitBehavior::update() {
//    Unit* target = pickTarget();
//    if(target != nullptr) {
//        mUnit->attack(target);
//    } else 
    {
        updatePathfinding();
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
        Object* objAt = mAttackableObjects[i] = world->at(mAdjacentPos[i]);
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

void UnitBehavior::updatePathfinding() {
    if(mWaypoint == nullptr) {
        findNextWaypoint();
    }
    std::vector<Waypoint*> adjacentWaypoints = Game::get()->world()->adjacent<Waypoint>(mUnit);
    for(Waypoint* w : adjacentWaypoints) {
        if(w == mWaypoint) {
            mWaypoint->collect();
            findNextWaypoint();
        }
    }
    moveTo(mWaypoint->pos());
}

void UnitBehavior::findNextWaypoint() {
    int minId = 10;
    std::vector<Waypoint*> waypoints = Game::get()->world()->findAll<Waypoint>();
    for(Waypoint* w : waypoints) {
        if(w->id() < minId) {
            mWaypoint = w;
            minId = w->id();
        }
    }
}

void UnitBehavior::moveTo(const Vector2& pos) {
    Pathfinding pathfinding;
    const Path& path = pathfinding.findPath(mUnit->pos(), pos);
    const Vector2& direction = path.steps[0] - mUnit->pos();
    moveDirection(direction);
}

void UnitBehavior::moveDirection(const Vector2& direction) {
    World* world = Game::get()->world();
    Vector2 targetPos = mUnit->mPos + direction;
    if(world->at(targetPos) == nullptr && world->isInBounds(targetPos)) {
        float deltaTime = Game::get()->time()->delta();
        mUnit->mPos += direction * mUnit->mSpeed * deltaTime;
    }
}

void UnitBehavior::move() {
    Vector2 direction;
    if(mAttackableObjects[1] == nullptr) {
        direction.y += mUnit->side();
    } else {
        if(mAttackableObjects[0] == nullptr && mAdjacentPos[0].xInt() >= mStartingX - 1) {
            direction.x -= 1;
        } else {
            if(mAttackableObjects[2] == nullptr && mAdjacentPos[2].xInt() <= mStartingX + 1) {
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

    moveDirection(direction);
}
