#ifndef _TIME_H_
#define _TIME_H_

#include <ctime>

class Time
{
public:
    Time();
    ~Time();

    void start();
    void startFrame();
    void endFrame();
    float get();
    float delta();

private:
    float getTime();

    float mFps;
    float mInvFps;

    float mStartTime;
    float mFrameStartTime;
    float mDeltaTime;
};

#endif