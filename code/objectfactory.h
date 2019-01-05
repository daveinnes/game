#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include "vector.h"
#include "object.h"

class ObjectFactory {
public:
    template <class T>
    static T* newObject(const Vector2& pos, const Vector2& dimensions) {
        Object* obj = newObject(pos, dimensions, T::kChar);
        if(obj != nullptr) {
            return obj->as<T>();
        }
        return nullptr;
    }

    static Object* newObject(const Vector2& pos, const Vector2& dimensions, char c);
};

#endif