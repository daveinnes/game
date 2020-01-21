#include "waypoint.h"
#include "game.h"
#include "world.h"

Waypoint::Waypoint(const Vector2& pos, const Vector2& dimensions, char c)
:Object(pos, dimensions, c) {
    mId = c - 48;
}

Waypoint::~Waypoint() {

}

void Waypoint::collect() {
    Game::get()->world()->remove(this);
}

void Waypoint::render(Render* r) {
    Object::render(r);
}