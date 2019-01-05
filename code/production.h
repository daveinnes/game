#ifndef _PRODUCTION_H_
#define _PRODUCTION_H_

#include <vector>

#include "building.h"

class Player;
class Unit;

class Production : public Building
{
public:
    static const int kType = 'prod';
    static const char kChar = '~';

    Production(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Production();

    bool full();
    void spawn(Unit* unit);
    int queueSize() { return mUnits.size(); }
    bool canBuildUnit();

    virtual bool canSpawn();
    virtual void buildUnit(char c);

    //Building
    void finishBuild() override;

    //Object
    void update() override;
    void render(Render* render) override;
    bool implementsType(int type) override { return type == kType || Building::implementsType(type); }
    int getType() override { return kType; }

private:
    void calculateSpawnPos();

    Vector2 mSpawnPos;
    Unit* mPendingUnit;
    std::vector<Unit*> mUnits;
};

#endif