#include "pylon.h"
#include "tuning.h"
#include "assert.h"
#include "render.h"
#include "player.h"

Pylon::Pylon(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: MultiBuilding(pos, dimensions, tuning, c) {
    mSupplyPerNode = tuning["supplyPerNode"].asInt();
    mMaxSupply = dimensions.x * dimensions.y * mSupplyPerNode;
}

Pylon::~Pylon() {
}

void Pylon::finishBuild() {
    MultiBuilding::finishBuild();
    int& supply = mPlayer->supply();
    supply += mSupplyPerNode;
}

void Pylon::die() {
    int& supply = mPlayer->supply();
    supply -= mSupplyPerNode * mNodeCount;
    MultiBuilding::die();
}

void Pylon::update() {
    MultiBuilding::update();
}