#ifndef _MINE_H_
#define _MINE_H_

#include "gatherer.h"

class Mine : public Gatherer
{
public:
    static const int kType = 'mine';
    static const char kChar = '.';

    Mine(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning);
    ~Mine() {};

    //Gatherer
    void deposit(Resource* bank, int amount) override;
    char getBuiltChar() override;

    //Object
    bool implementsType(int type) override { return type == kType || Gatherer::implementsType(type); }
    int getType() override { return kType; }

};

#endif