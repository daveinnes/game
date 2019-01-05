#include "playerbehavior.h"
#include "tuning.h"
#include "player.h"
#include "game.h"
#include "time.h"
#include "base.h"
#include "production.h"
#include "pylon.h"
#include "mine.h"

PlayerBehavior::PlayerBehavior(Player* player, const Json::Value& tuning)
: mPlayer(player)
, mUpdatePeriod(tuning["period"].asFloat())
, mLastUpdateTime(-100.f) {
}

PlayerBehavior::~PlayerBehavior() {
}

void PlayerBehavior::update() {
    float time = Game::get()->time()->get();
    if(time - mLastUpdateTime >= mUpdatePeriod) {
        mLastUpdateTime = time;

        Base* base = mPlayer->selectedBase();

        Production* prod = base->findAny<Production>();
        if(prod != nullptr && !prod->isBuilt() && prod->canBuild()) {
            prod->startBuild();
        }
        Mine* mine = base->findAny<Mine>();
        if(mine != nullptr && !mine->isBuilding() && mine->canBuild()) {
            mine->startBuild();
        }
        if(prod != nullptr && prod->isBuilt() && prod->canBuildUnit()) {
            prod->buildUnit(Unit::kChar);
        }

        Pylon* pylon = base->findAny<Pylon>();
        if(pylon != nullptr 
            && mPlayer->usedSupply() >= mPlayer->supply() - 1
            && pylon->queuedCount() == 0
            && pylon->canBuild()) {
            pylon->startBuild();
        }
    }
}