#include "render.h"
#include <cstring>
#include "assert.h"

Render::Render(int width, int height)
: mWidth(width)
, mHeight(height) {
    mWin = newwin(mHeight, mWidth, 0, 0);
    mScreen = new char[mWidth * mHeight];
}

Render::~Render() {
    delete [] mScreen;
}

void Render::put(int x, int y, char c) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    char& s = at(x, y);
    s = c;
}

char& Render::at(int x, int y) {
    ASSERT(x >= 0 && x < mWidth && y >= 0 && y < mHeight);
    return mScreen[y*mWidth + x];
}

void Render::beginFrame() {
    memset(mScreen, ' ', sizeof(char) * mWidth * mHeight);
}

void Render::draw() {
    for(int y = 0; y < mHeight; ++y) {
        for(int x = 0; x < mWidth; ++x) {
            char& c = at(x, y);
            wmove(mWin, y, x);
            waddch(mWin, c);
        }
    }
    wrefresh(mWin);
}