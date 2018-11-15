#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "vector.h"

class World;
class Render;
class Input;

class Object {
public:
    Object(Vector2 pos, char c);

    void update(World* world, Input* input);
    void render(Render* render);
    Vector2& getPos() { return mPos; }
    
    void build() {}
    
    template<class T> 
    bool is() {
        return mChar == T::kChar;
    }

protected:
    char mChar;
    Vector2 mPos;

private:
};

#endif