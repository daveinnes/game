#ifndef _LAB_H_
#define _LAB_H_

#include "gatherer.h"

class Lab : public Gatherer
{
public:
    static const int kType = 'labr';
    static const char kChar = ',';

    Lab(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning);
    ~Lab() {};

    bool implementsType(int type) override { return type == kType || Gatherer::implementsType(type); }
    int getType() override { return kType; }

    void deposit(Resource* bank, int amount) override;
    char getBuiltChar() override;
};

#endif