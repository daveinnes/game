#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include "vector.h"

class Object;

class ObjectFactory {
public:
    static Object* newObject(Vector2 pos, char c);
};

#endif