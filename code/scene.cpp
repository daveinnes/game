#include "scene.h"

#include <cmath>
#include <algorithm>

#include "objectfactory.h"
#include "object.h"
#include "render.h"
#include "assert.h"
#include "textmatrix.h"
#include "unit.h"

Scene::Scene()
: mWidth(0)
, mHeight(0) 
, mPos(0, 0) {
}

Scene::Scene(const TextMatrix& map)
: Scene() {
    init(map);
}

Scene::Scene(const char* path) 
: Scene() {
    TextMatrix map(path);
    init(map);
}

Scene::~Scene() {
    for(Object* obj : mObjects) {
        delete obj;
    }
    mObjects.clear();
}

void Scene::init(const TextMatrix& map) {
    for(int y = 0; y < map.getHeight(); ++y) {
        for(int x = 0; x < map.getWidth(); ++x) {
            if(atLocal(x, y) == nullptr) {
                char c = map.get(x, y);
                if(c != ' ') {
                    Vector2 dimensions = map.getDimensions(x, y);
                    Object* newObj = ObjectFactory::newObject(Vector2(mPos.x + x, mPos.y + y), dimensions, c);
                    if(newObj != nullptr) {
                        add(newObj);
                    }
                }
            }
        }
    }
    mWidth = map.getWidth();
    mHeight = map.getHeight();
}

void Scene::add(Object* object) {
    mObjects.push_back(object);
}

bool Scene::remove(Object* object) {
    std::vector<Object*>::iterator it = std::find(mObjects.begin(), mObjects.end(), object);
    if(it != mObjects.end()) {
        mObjects.erase(it);
        delete object;
        return true;
    }
    return false;
}

void Scene::removeDead() {
    std::vector<Unit*> toRemove;
    for(Object* obj : mObjects) {
        Unit* unit = obj->as<Unit>();
        if(unit != nullptr && unit->isDead()) {
            toRemove.push_back(unit);
        }
    }
    for(Unit* unit : toRemove) {
        remove(unit);
    }
}
void Scene::update() {
    for(Object* object : mObjects) {
        object->update();
    }
    removeDead();
}

void Scene::render(Render* render) {
    for(Object* object : mObjects) {
        object->render(render);
    }
}

Object* Scene::at(const Vector2& pos) {
    return at(std::floor(pos.x), std::floor(pos.y));
}

Object* Scene::at(int x, int y) {
    for(Object* object : mObjects) {
        if(object->hitTest(x, y)) {
            return object;
        }
    }
    return nullptr;
}

Object* Scene::atLocal(int x, int y) {
     for(Object* object : mObjects) {
         if(object->hitTest(mPos.x + x, mPos.y + y)) {
             return object;
         }
     }
     return nullptr;
}