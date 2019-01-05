#include "gatherer.h"
#include "game.h"
#include "tuning.h"
#include "player.h"
#include "time.h"

Gatherer::Gatherer(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
:MultiBuilding(pos, dimensions, tuning, c)
, mResource(0.f) {
    mCollectionRate = tuning["rate"].asFloat();
    mDepositThreshold = tuning["threshold"].asInt();
}

void Gatherer::update() {
    if(mNodeCount > 0) {
        Time* time = Game::get()->time();
        mResource += time->delta() * mCollectionRate * mNodeCount;
        if(mResource >= mDepositThreshold) {
            Resource* bank = mPlayer->bank();
            mResource -= mDepositThreshold;
            deposit(bank, mDepositThreshold);
        }
    }
    MultiBuilding::update();
}

