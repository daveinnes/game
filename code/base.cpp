#include "base.h"
#include "game.h"
#include "input.h"
#include "mine.h"
#include "lab.h"
#include "production.h"
#include "unit.h"
#include "nexus.h"
#include "pylon.h"
#include "render.h"

Base::Base(const TextMatrix& map, const Vector2& pos, Player* player)
: Scene()
, mPlayer(player)
, mSelected(false) {
    mPos = pos;
    init(map);
    for(Object* o : mObjects) {
        o->player() = player;
    }
}

Base::~Base() { 
}

void Base::select(bool selected) {
    mSelected = selected;
    for(Object* obj : mObjects) {
        char& color = obj->colour();
        color = selected ? COLOR_GREEN : COLOR_WHITE;
    }
}

bool Base::isNexusBuilt() {
    Nexus* nexus = findAny<Nexus>();
    if(nexus != nullptr) {
        return nexus->isBuilt();
    }
    return false;
}

void Base::update() {
    Scene::update();
}

void Base::processInput() {
    if(mSelected) {
        int input = Game::get()->input()->get();
        switch(input) {
            case 'e': {
                if(isNexusBuilt()) {
                    build<Mine>();
                }
                break;
            }
            case 'r': {
                if(isNexusBuilt()) {
                    build<Lab>();
                }
                break;
            }
            case 'b': {
                if(isNexusBuilt()) {
                    build<Production>();
                }
                break;
            }
            case 'p': {
                if(isNexusBuilt()) {
                    build<Pylon>();
                }
                break;
            }
            case Unit::kChar: {
                std::vector<Production*> productions =  findAll<Production>();
                Production* leastQueued = nullptr;
                for(Production* production : productions) {
                    if(production->isBuilt()) {
                        if(leastQueued == nullptr || production->queueSize() < leastQueued->queueSize()) {
                            leastQueued = production;
                        }
                    }
                }
                if(leastQueued != nullptr) {
                    leastQueued->buildUnit(Unit::kChar);
                }
                break;
            }
            case 'n': {
                build<Nexus>();
                break;
            }
        }
    }
}