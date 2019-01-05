#ifndef _PYLON_H_
#define _PYLON_H_

#include "multibuilding.h"

class Pylon : public MultiBuilding {
public:
    static const int kType = 'pyln';
    static const char kChar = '_';
    static const char kBuiltChar = '@';

    Pylon(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Pylon();

    int supply() { return mNodeCount * mSupplyPerNode; }
    int maxSupply() { return mMaxSupply; }

    //Unit
    void die() override;

    //Multibuilding
    char getBuiltChar() override { return kBuiltChar; }

    //Buildable
    void finishBuild() override;

    //Object
    void update() override;
    bool implementsType(int type) override { return type == kType || MultiBuilding::implementsType(type); }
    int getType() override { return kType; }

private:
    int mSupplyPerNode;
    int mMaxSupply;
};

#endif