#ifndef _WAYPOINT_H_
#define _WAYPOINT_H_

#include "object.h"

class Render;

class Waypoint : public Object
{
public:
    static const int kType = 'wypt';

    Waypoint(const Vector2& pos, const Vector2& dimensions, char c);
    virtual ~Waypoint();

    //Object
    void render(Render* r) override;
    bool implementsType(int type) override { return type == kType; }
    int getType() override { return kType; }

    int id() { return mId; }
    void collect();

private:
    int mId;
};
#endif