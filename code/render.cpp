#include "render.h"
#include <cstring>
#include "assert.h"
#include "tuning.h"

Render::Render(int width, int height, const Json::Value& tuning)
: mWidth(width)
, mHeight(height)
, mBlinkTime(0.f)
, mBlink(false) {
    mWin = newwin(mHeight, mWidth, 0, 0);
    mScreen = new char[mWidth * mHeight];
    mColour = new char[mWidth * mHeight];
    mBlinkMap = new bool[mWidth * mHeight];
    mBlinkPeriod = tuning["blinkPeriod"].asFloat();
}

Render::~Render() {
    delete [] mScreen;
    delete [] mColour;
}

void Render::put(const Vector2& pos, char ch, char colour) {
    put(pos.x, pos.y, ch, colour);
}

void Render::put(int x, int y, char ch, char colour) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    char& charAt = at(x, y);
    charAt = ch;
    char& colAt = colourAt(x, y);
    colAt = colour;
}

void Render::fill(int x, int y, int width, int height, char c, char colour) {
    for(int xx = 0; xx < width; ++xx) {
        for(int yy = 0; yy < height; ++yy) {
            put(x+xx, y+yy, c, colour);
        }
    }
}

void Render::fillBlinkAt(int x, int y, int width, int height, bool blink) {
    for(int xx = 0; xx < width; ++xx) {
        for(int yy = 0; yy < height; ++yy) {
            blinkAt(x+xx, y+yy) = blink;
        }
    }
}

char& Render::at(int x, int y) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    return mScreen[y*mWidth + x];
}

char& Render::colourAt(int x, int y) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    return mColour[y*mWidth + x];
}

bool& Render::blinkAt(int x, int y) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    return mBlinkMap[y*mWidth + x];
}

void Render::beginFrame() {
    clear();
}

void Render::clear() {
    memset(mScreen, ' ', sizeof(char) * mWidth * mHeight);
    memset(mColour, ((char)COLOR_WHITE), sizeof(char) * mWidth * mHeight);
    memset(mBlinkMap, false, sizeof(bool) * mWidth * mHeight);
}

void Render::draw(float time) {
    if(time - mBlinkTime > mBlinkPeriod) {
        mBlink = !mBlink;
        mBlinkTime = time; 
    }

    for(int y = 0; y < mHeight; ++y) {
        for(int x = 0; x < mWidth; ++x) {
            char& c = at(x, y);
            bool& b = blinkAt(x, y);
            if(b && mBlink) {
                c = ' ';
            }
            char& colour = colourAt(x, y);
            wattron(mWin, COLOR_PAIR(colour));
            mvwaddch(mWin, y, x, c);
        }
    }

    wrefresh(mWin);

}