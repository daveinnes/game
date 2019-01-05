#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "object.h"

class Object;
class Render;
class Input;
class TextMatrix;

class Scene {
public:
    Scene();
    Scene(const TextMatrix& map);
    Scene(const char* path);
    virtual ~Scene();

    void init(const TextMatrix& map);
    void add(Object* object);
    void removeDead();

    virtual bool remove(Object* object);
    virtual void update();
    virtual void render(Render* render);
    
    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }
    Vector2& pos() { return mPos; }

    virtual Object* at(const Vector2& pos);
    virtual Object* at(int x, int y);
    Object* atLocal(int x, int y);

    template <class T>
    T* findAny() {
        for(Object* o : mObjects) {
             if(o->is<T>()) {
                return o->as<T>();
             }
        }
        return nullptr;
    }

    template <class T>
    std::vector<T*> findAll() {
        std::vector<T*> objs;
        for(Object* o : mObjects) {
             if(o->is<T>()) {
                objs.push_back(o->as<T>());
             }
        }
        return objs;
    }

protected:
    std::vector<Object*> mObjects;
    int mWidth;
    int mHeight;
    Vector2 mPos;
};

#endif