#include "object.h"
#include "world.h"
#include "render.h"
#include "input.h"

Object::Object(Vector2 pos, char c) 
: mPos(pos)
, mChar(c) {

}

void Object::update(World* world, Input* input) {

}

void Object::render(Render* r) {
    r->put(mPos.x, mPos.y, mChar);
}