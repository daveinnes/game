#ifndef _BUILDABLE_H_
#define _BUILDABLE_H_

#include "resource.h"
#include "object.h"
    
class Player;

class Buildable : public Object {
public:
    static const int kType = 'blda';
    static const char kChar = 'm';

    Buildable(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Buildable();

    virtual void update();
    virtual void startBuild();
    virtual void finishBuild();
    virtual bool canBuild();

    bool isBuilt() { return mBuilt; }
    bool isBuilding() { return mBuilding; }
    void subtractCost();
    void addSupply();
    void removeSupply();
    void startBuildNoCost();

    Player*& player() { return mPlayer; }
    Resource& cost() { return mCost; }

    //Object
    bool implementsType(int type) override { return type == kType; }
    int getType() override { return kType; }

protected:
    bool mBuilt;
    bool mBuilding;
    float mBuildStartTime;
    
private:
    Resource mCost;
    float mBuildTime;
    int mSupplyCost;
};

#endif