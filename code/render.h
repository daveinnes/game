#ifndef _RENDER_H_
#define _RENDER_H_

#include <ncurses.h>
#include "vector.h"

namespace Json {
    class Value;
}

class Render {
public:
    Render(int width, int height, const Json::Value& tuning);
    ~Render();

    void put(const Vector2& pos, char ch, char colour);
    void put(int x, int y, char ch, char colour);
    void fill(int x, int y, int width, int height, char ch, char colour);
    char& at(int x, int y);
    char& colourAt(int x, int y);
    void fillBlinkAt(int x, int y, int width, int height, bool blink);
    bool& blinkAt(int x, int y);
    void beginFrame();
    void draw(float time);
    void clear();

    WINDOW* mWin;
    char* mScreen;
    char* mColour;
    bool* mBlinkMap;
    int mWidth;
    int mHeight;
    float mBlinkPeriod;
    float mBlinkTime;
    bool mBlink;
};

#endif