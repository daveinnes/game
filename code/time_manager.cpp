#include "time_manager.h"
#include "game.h"
#include "tuning.h"

TimeManager::TimeManager()
: mStartTime(0)
, mFrameStartTime(0)
, mDeltaTime(0) {
    mFps = Game::get()->tuning()->get("game")["fps"].asFloat();
    mInvFps = ((float) 1) / mFps;
}

TimeManager::~TimeManager() {

}

void TimeManager::start() {
    mStartTime = getTime();
    mFrameStartTime = mStartTime;
}

void TimeManager::startFrame() {
    float t = getTime();
    mDeltaTime = t - mFrameStartTime;
    mFrameStartTime = t;
}

void TimeManager::endFrame() {
    while((getTime() - mFrameStartTime) < mInvFps);
}

float TimeManager::get() {
    return mFrameStartTime;
}

float TimeManager::delta() {
    return mDeltaTime;
}

float TimeManager::getTime() {
    float time = ((float)clock()) / CLOCKS_PER_SEC;
    return time;
}
