#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <string>

class Object;
class Render;
class Input;

class World {
public:
    World();

    void init(const std::string& mapText);
    void add(Object* object);
    void update(Input* input);
    void render(Render* render);
    
    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

    template <class T>
    T* find() {
        for(Object* o : mObjects) {
            if(o->is<T>())
                return static_cast<T*>(o);
            }
        }
        return nullptr;
    }

private:
    std::vector<Object*> mObjects;
    int mWidth;
    int mHeight;
};

#endif