#include "mine.h"
#include "game.h"
#include "tuning.h"
#include "player.h"
#include "time.h"

Mine::Mine(Vector2 pos)
: Object(pos, kChar)
, mMining(false) {
    const Json::Value& t = Game::get()->tuning()->get("mine");
    mCollectionRate = t["rate"].asFloat();
    mDepositThreshold = t["threshold"].asInt();
}

void Mine::build() {
    mChar = 'm';
    startMining();
}

void Mine::update() {
    if(mMining) {
        float time = Game::get()->time()->get();
        float resource = ( time - mMiningStartTime) * mCollectionRate;
        if( resource >= mDepositThreshold) {
            mMiningStartTime = time;
            Bank* bank = Game::get()->player()->bank();
            bank->money += mDepositThreshold;
        }
    }
}

void Mine::startMining() {
    mMiningStartTime = Game::get()->time()->get();
    mMining = true;
}
