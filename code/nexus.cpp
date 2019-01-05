#include "nexus.h"
#include "tuning.h"
#include "player.h"

Nexus::Nexus(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Building(pos, dimensions, tuning, c) {
    mSupply = tuning["supply"].asInt();
}

Nexus::~Nexus() {
}

void Nexus::finishBuild() {
    Building::finishBuild();
    mPlayer->supply() += mSupply;
    Building::finishBuild();
}

void Nexus::die() {
    mPlayer->supply() -= mSupply;
    Building::die();
}