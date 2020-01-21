#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "vector.h"

class World;
class Render;
class Input;
class Player;

class Object {
public:
    Object(const Vector2& pos, const Vector2& dimensions, char c);
    virtual ~Object() {}
    
    virtual void update();
    virtual void render(Render* render);
    virtual bool implementsType(int type) = 0;
    virtual int getType() = 0;
    
    template<class T> 
    bool is() {
        return implementsType(T::kType);
    }

    template<class T> 
    T* as() {
        if(implementsType(T::kType)) {
            return static_cast<T*>(this);
        }
        return nullptr;
    }

    bool isAdjacent(Object* obj) const;
    bool hitTest(int x, int y);
    Vector2& pos() { return mPos; }
    Vector2& dim() { return mDimensions; }
    char renderChar() { return mChar; }
    char& colour() { return mColour; }
    Player*& player() { return mPlayer; }
    int side();
    
protected:
    char mColour;
    char mChar;
    Vector2 mPos;
    Vector2 mDimensions;
    Player* mPlayer;
    int mSide;

private:
};

#endif