#include "objectfactory.h"
#include "object.h"
#include "mine.h"

Object* ObjectFactory::newObject(Vector2 pos, char c) {
    Object* newObject = nullptr;
    switch(c) {
        case Mine::kChar: {
            newObject = new Mine(pos);
            break;
        }
        case ' ': {
            break;
        }
        default: {
            newObject = new Object(pos, c);
            break;
        }
    }
    return newObject;
}
