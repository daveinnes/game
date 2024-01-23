#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <ctime>

class TimeManager
{
public:
    TimeManager();
    ~TimeManager();

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