#ifndef _MINERAL_PATCH_H_
#define _MINERAL_PATCH_H_

#include "object.h"

class Mine : public Object {
public:
    static const char kChar = '.';
    Mine(Vector2 pos);

    virtual void build();
    virtual void update();
private:

    void startMining();

    bool mMining;
    float mMiningStartTime;
    float mCollectionRate;
    int mDepositThreshold;
};

#endif