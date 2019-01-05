#ifndef _MULTIBUILDING_H_
#define _MULTIBUILDING_H_

#include "building.h"

class MultiBuilding : public Building
{
public:
    static const int kType = 'mbld';
    static const char kChar = 'm';

    MultiBuilding(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~MultiBuilding() {};

    bool full();
    void addNode() { ++mNodeCount; }
    int queuedCount() { return mQueuedCount; }

    //Buildable
    bool canBuild() override;
    void finishBuild() override;
    void startBuild() override;

    //Object
    void update() override;
    void render(Render* r) override;
    bool implementsType(int type) override { return type == kType || Building::implementsType(type); }
    int getType() override { return kType; }

protected:
    virtual char getBuiltChar() = 0;

    int mNodeCount;
    int mQueuedCount;
};

#endif