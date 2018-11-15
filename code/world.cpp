#include "world.h"
#include "object.h"
#include "render.h"
#include "objectfactory.h"
#include "assert.h"

World::World() 
: mWidth(0)
, mHeight(0) {

}

void World::init(const std::string& mapText) {
    int x = 0;
    int y = 0;
    for(char c : mapText) {
        if(c == '\n') {
            x = 0;
            ++y;
            continue;
        }
        Object* newObj = ObjectFactory::newObject(Vector2(x,y), c);
        if(newObj != nullptr) {
            add(newObj);
            mWidth = std::max(mWidth, newObj->getPos().x + 1);
            mHeight = std::max(mHeight, newObj->getPos().y + 1);
        }
        ++x;
    }
}

void World::add(Object* object) {
    mObjects.push_back(object);
}

void World::update(Input* input) {
    for(Object* object : mObjects) {
        object->update(this, input);
    }
}

void World::render(Render* render) {
    for(Object* object : mObjects) {
        object->render(render);
    }
}