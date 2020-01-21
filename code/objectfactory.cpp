#include "objectfactory.h"
#include "object.h"
#include "tuning.h"
#include "game.h"
#include "mine.h"
#include "lab.h"
#include "production.h"
#include "unit.h"
#include "nexus.h"
#include "pylon.h"
#include "wall.h"
#include "waypoint.h"

Object* ObjectFactory::newObject(const Vector2& pos, const Vector2& dimensions, char c) {
    Object* newObject = nullptr;
    Tuning* tuning = Game::get()->tuning();
    switch(c) {
        case Mine::kChar: {
            newObject = new Mine(pos, dimensions, tuning->get("mine"));
            break;
        }
        case Lab::kChar: {
            newObject = new Lab(pos, dimensions, tuning->get("lab"));
            break;
        }
        case Production::kChar: {
            newObject = new Production(pos, dimensions, tuning->get("barracks"), '~');
            break;
        }
        case Unit::kChar: {
            newObject = new Unit(pos, dimensions, tuning->get("tank"), Unit::kChar);
            break;
        }
        case Nexus::kChar: {
            newObject = new Nexus(pos, dimensions, tuning->get("nexus"), Nexus::kChar);
            break;
        }
        case Pylon::kChar: {
            newObject = new Pylon(pos, dimensions, tuning->get("pylon"), Pylon::kChar);
            break;
        }
        case Wall::kChar: {
            newObject = new Wall(pos, dimensions, tuning->get("wall"), Wall::kChar);
            break;
        }
        default: {
            break;
        }
    }

    if(newObject == nullptr) {
        int waypointId = c - 48;
        if(waypointId >= 0 && waypointId <= 9) {
            newObject = new Waypoint(pos, dimensions, c);
        }
    }
    return newObject;
}
