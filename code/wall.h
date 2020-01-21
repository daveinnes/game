#ifndef _WALL_H_
#define _WALL_H_

#include "building.h"

class Unit;

class Wall : public Building {
public:
    static const int kType = 'wall';
    static const char kChar = '%';

    Wall(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Wall();

    //Unit
    void receiveAttack(Unit* source) override;

    //Object
    bool implementsType(int type) override { return type == kType || Building::implementsType(type); }
    int getType() override { return kType; }
};

#endif