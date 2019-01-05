#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "scene.h"

class Render;

namespace Json {
    class Value;
}

class World : public Scene {
public:
    World(const Json::Value& tuning);
    virtual ~World();

    bool isInBounds(const Vector2& pos);
    void update() override;
    void render(Render* render) override;

    //Scene
    bool remove(Object* obj) override;
    Object* at(const Vector2& pos) override;
    Object* at(int x, int y) override;

private:
    void initBases(const Json::Value& tuning);

    std::vector<Scene*> mScenes;
};

#endif