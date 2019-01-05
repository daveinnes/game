#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "unit.h"

class Building : public Unit {
public:
    static const int kType = 'bldg';
    static const char kChar = 'b';

    Building(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Building();

    void updateDamage();

    //Unit
    void createBehavior() override;
    void attack(Unit* target) override;
    void receiveAttack(Unit* source) override;
    void die() override;

    //Buildable
    bool canBuild() override;

    //Object
    void update() override;
    void render(Render* render) override;
    bool implementsType(int type) override { return type == kType || Unit::implementsType(type); }
    int getType() override { return kType; }

protected:
    int mSectionsAlive;
};

#endif