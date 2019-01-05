#ifndef _GATHERER_H_
#define _GATHERER_H_

#include "multibuilding.h"

namespace Json {
    class Value;
}

class Player;

class Gatherer : public MultiBuilding {
public:
    static const int kType = 'gthr';
    static const char kChar = 'g';

    Gatherer(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    
    //Object
    void update() override;
    bool implementsType(int type) override { return type == kType || MultiBuilding::implementsType(type); }
    int getType() override { return kType; }

protected:
    virtual void deposit(Resource* bank, int amount) = 0;

private:
    float mResource;
    int mQueuedCount;
    int mWorkerCount;

    float mCollectionRate;
    int mDepositThreshold;
};

#endif