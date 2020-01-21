#include "wall.h"

Wall::Wall(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
:Building(pos, dimensions, tuning, c) {
    mBuilt = true;
}

Wall::~Wall() {
}

void Wall::receiveAttack(Unit* source) {
    Unit::receiveAttack(source);
}
