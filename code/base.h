#ifndef _BASE_H_
#define _BASE_H_

#include "scene.h"

class Player;

class Base : public Scene
{
public:
    Base(const TextMatrix& map, const Vector2& pos, Player* player);
    virtual ~Base();
    
    void select(bool selected);
    void processInput(); 

    //Scene
    void update() override;

    template <class T>
    T* build() {
        std::vector<T*> objs = findAll<T>();
        for(T* obj : objs) {
            if(obj->canBuild()) {
                obj->startBuild();
                return obj;
            }
        }
        return nullptr;
    }

    template <class T>
    T* place() {
        std::vector<T*> objs = findAll<T>();
        for(T* obj : objs) {
            obj->finishBuild();
            return obj;
        }
        return nullptr;
    }

private:
    bool isNexusBuilt();
    Player* mPlayer;
    bool mSelected;
};
#endif