#ifndef _UNIT_BEHAVIOR_H_
#define _UNIT_BEHAVIOR_H_

class Unit;
class Object;
class Pathfinding;
class Vector2;
class Waypoint;

#include <vector>
#include "vector.h"

class UnitBehavior
{
public:
    UnitBehavior(Unit* unit);
    ~UnitBehavior() {};

    void update();
private:
    void updatePathfinding();
    void findNextWaypoint();
    Unit* pickTarget();
    void move();
    void moveTo(const Vector2& destination);
    void moveDirection(const Vector2& direction);

    Unit* mUnit;
    int mStartingX;
    Vector2 mAdjacentPos[3];
    Object* mAttackableObjects[3];
    Pathfinding* mPathfinding;
    Waypoint* mWaypoint;
};

#endif