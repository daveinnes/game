#include "time.h"
#include "game.h"
#include "tuning.h"

Time::Time()
: mStartTime(0)
, mFrameStartTime(0)
, mDeltaTime(0) {
    mFps = Game::get()->tuning()->get("time")["fps"].asFloat();
    mInvFps = ((float) 1) / mFps;
}

Time::~Time() {

}

void Time::start() {
    mStartTime = getTime();
    mFrameStartTime = mStartTime;
}

void Time::startFrame() {
    float t = getTime();
    mDeltaTime = t - mFrameStartTime;
    mFrameStartTime = t;
}

void Time::endFrame() {
    while((getTime() - mFrameStartTime) < mInvFps);
}

float Time::get() {
    return mFrameStartTime;
}

float Time::delta() {
    return mDeltaTime;
}

float Time::getTime() {
    float time = ((float)clock()) / CLOCKS_PER_SEC;
    return time;
}
