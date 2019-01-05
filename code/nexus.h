#ifndef _NEXUS_H_
#define _NEXUS_H_

#include "building.h"

class Nexus : public Building
{
public:
    static const int kType = 'nexs';
    static const char kChar = '#';

    Nexus(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Nexus();
    
    //Unit
    void die() override;

    //Buildable
    void finishBuild() override;

    //Object
    bool implementsType(int type) override { return type == kType || Building::implementsType(type); }
    int getType() override { return kType; }

private:
    int mSupply;
};

#endif