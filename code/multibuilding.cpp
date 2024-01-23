#include "multibuilding.h"
#include "render.h"
#include "assert.h"
#include "game.h"
#include "time_manager.h"

MultiBuilding::MultiBuilding(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Building(pos, dimensions, tuning, c)
, mNodeCount(0)
, mQueuedCount(0) {
}

bool MultiBuilding::full() {
    bool isFull = (mNodeCount + mQueuedCount) >= mSectionsAlive;
    return isFull;
}

bool MultiBuilding::canBuild() {
    bool canBuild = Buildable::canBuild() && !full();
    return canBuild;
}

void MultiBuilding::startBuild() {
    subtractCost();
    addSupply();
    if(mQueuedCount == 0) {
        mBuildStartTime = Game::get()->time()->get();
        mBuilding = true;
    }
    ++mQueuedCount;
}

void MultiBuilding::finishBuild() {
    ASSERT(mQueuedCount > 0);
    --mQueuedCount;
    ++mNodeCount;
    if(mQueuedCount > 0) {
        mBuildStartTime = Game::get()->time()->get();
    } else {
        mBuilding = false;
    }
}

void MultiBuilding::update() {
    Buildable::update();
}

void MultiBuilding::render(Render* r) {
    int buildingCount = mQueuedCount;
    int left = mNodeCount;
    for(int y = 0; y < mDimensions.y; ++y) {
        for(int x = 0; x < mDimensions.x; ++x) {
            int index = y * mDimensions.x + x;
            if(index < mSectionsAlive) {
                Vector2 offset(x, y);
                Vector2 pos = mPos + offset;
                char c = mChar;
                if(left > 0) {
                    c = getBuiltChar();
                    --left;
                } else if(buildingCount > 0) {
                    c = getBuiltChar();
                    r->blinkAt(pos.x, pos.y) = true;
                    --buildingCount;
                }
                
                r->put(pos, c, mColour);
            }
        }
    }
}