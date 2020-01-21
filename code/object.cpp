#include "object.h"

#include <cmath>

#include "world.h"
#include "render.h"
#include "input.h"
#include "assert.h"
#include "player.h"

Object::Object(const Vector2& pos, const Vector2& dimensions, char c) 
: mPos(pos)
, mDimensions(dimensions)
, mChar(c)
, mPlayer(nullptr) 
, mSide(0)
, mColour(COLOR_WHITE) {
    ASSERT(mDimensions.x > 0);
    ASSERT(mDimensions.y > 0);
}

void Object::update() {

}

void Object::render(Render* render) {
    render->put(mPos.x, mPos.y, mChar, mColour);
}

bool Object::isAdjacent(Object* obj) const {
    const Vector2& distance = obj->pos() - mPos;
    if(distance.length() <= 1.0f) {
        return true;
    }
    return false;
}

bool Object::hitTest(int x, int y) {
    bool hit =  x >= std::floor(mPos.x)
                && x < (std::floor(mPos.x) + mDimensions.x)
                && y >= std::floor(mPos.y)
                && y < (std::floor(mPos.y) + mDimensions.y);
    return hit;
}

int Object::side() {
    return mPlayer->side();
}
