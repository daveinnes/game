#ifndef _UNIT_BEHAVIOR_H_
#define _UNIT_BEHAVIOR_H_

class Unit;
class Object;

#include "vector.h"

class UnitBehavior
{
public:
    UnitBehavior(Unit* unit);
    ~UnitBehavior() {};

    void update();
private:
    Unit* pickTarget();
    void move();

    Unit* mUnit;
    int mStartingX;
    Vector2 mAdjacentPos[3];
    Object* mAdjacentObjects[3];
};

#endif