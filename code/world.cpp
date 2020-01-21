#include "world.h"

#include <cmath>
#include <jsoncpp/json/json.h>

#include "game.h"
#include "player.h"
#include "base.h"
#include "textmatrix.h"
#include "objectfactory.h"
#include "nexus.h"
#include "mine.h"
#include "pylon.h"

World::World(const Json::Value& tuning) {
    if(tuning.isMember("bases")) {
        initBases(tuning["bases"]);
    } else if(tuning.isMember("map")) {
        initMap(tuning["map"]);
    }
}

World::~World() {
    for(Scene* scene : mScenes) {
        delete scene;
    }
}

void World::initBases(const Json::Value& tuning) {
    Player* player = Game::get()->player(0);

    mWidth = 0;
    mHeight = 0;
    const char* path = tuning["path"].asCString();
    int count = tuning["count"].asInt();

    Vector2 spacing;
    spacing.x = tuning["spacing"][0].asInt();
    spacing.y = tuning["spacing"][1].asInt();

    int margin = tuning["margin"].asInt();
    int startingWorkers = tuning["startingWorkers"].asInt();

    if(count > 0) {
        TextMatrix map(path);
        int x = margin;
        int y = 0;
        for(int i = 0; i < count; ++i) {
            Vector2 pos(x, y);
            Base* base = new Base(map, pos, player);
            mScenes.push_back(base);
            player->add(base);
            x += map.getWidth();
            if(i != count -1) {
                x += spacing.x;
            }
        }

        int selectedIndex = count / 2;
        player->selectBase(selectedIndex);
        Base* base = player->base(selectedIndex);
        base->place<Nexus>();
        Mine* mine = base->findAny<Mine>();
        for(int i = 0; i < startingWorkers; ++i) {
            mine->addNode();
            mine->addSupply();
        }

        x = margin;
        y += map.getHeight();
        y += spacing.y;

        if(count > 1) {
            player = Game::get()->player(1);
            map.flip();
            for(int i = 0; i < count; ++i) {
                Vector2 pos(x, y);
                Base* base = new Base(map, pos, player);
                mScenes.push_back(base);
                player->add(base);
                x += map.getWidth();
                if(i != count -1) {
                    x += spacing.x;
                }
            }

            x += margin;
            y += map.getHeight();

            player->selectBase(selectedIndex);
            base = player->base(selectedIndex);
            base->place<Nexus>();
            mine = base->findAny<Mine>();
            for(int i = 0; i < startingWorkers; ++i) {
                mine->addNode();
                mine->addSupply();
            }
        }

        mWidth = x + 1;
        mHeight = y + 1;
    }
}

void World::initMap(const Json::Value& tuning) {
    TextMatrix map(tuning.asCString());
    init(map);
}

Object* World::at(const Vector2& pos) {
    return at(std::floor(pos.x), std::floor(pos.y));
}

Object* World::at(int x, int y) {
    Object* atObj = Scene::at(x, y);
    if(atObj == nullptr) {
        for(Scene* scene : mScenes) {
            atObj = scene->at(x, y);
            if(atObj != nullptr) {
                break;
            }
        }
    }
    return atObj;
}

void World::update() {
    Scene::update();
    for(Scene* scene : mScenes) {
        scene->update();
    }
}

void World::render(Render* render) {
    Scene::render(render);
    for(Scene* scene : mScenes) {
        scene->render(render);
    }
}

bool World::remove(Object* obj) {
    for(Scene* scene : mScenes) {
        if(scene->remove(obj)) {
            return true;
        }
    }
    return Scene::remove(obj);
}

bool World::isInBounds(const Vector2& pos) {
    return pos.x >= 0 && pos.x < mWidth && pos.y >= 0 && pos.y < mHeight;
}
