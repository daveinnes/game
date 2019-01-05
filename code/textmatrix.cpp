#include "textmatrix.h"
#include "assert.h"
#include "util.h"

TextMatrix::TextMatrix(const char* path)
: mWidth(0)
, mHeight(0) {
    load(path);
}

TextMatrix::~TextMatrix() {

}

char TextMatrix::flip() {
    std::string newText;
    for(int y = mHeight - 1; y >= 0; --y) {
        for(int x = 0; x < mWidth; ++x) {
            char c = get(x, y);
            newText += c;
        }
        newText += '\n';
    }
    mText = newText;
}

void TextMatrix::load(const char* path) {
    mText = File::readText(path);
    int x = 0;
    int y = 0;
    for(char c : mText) {
        if(c == '\n') {
            mWidth = std::max(mWidth, x);
            mHeight = std::max(mHeight, y + 1);
            x = 0;
            ++y;
        } else {
            ++x;
        }
    }
}

char TextMatrix::get(int x, int y) const {
    ASSERT(x > -1 && x < mWidth && y > -1 && y < mHeight);
    return mText[y * (mWidth + 1) + x];
}

Vector2 TextMatrix::getDimensions(int x, int y) const {
    Vector2 dimensions;
    char startingChar = get(x, y);
    for(int yy = y; yy < getHeight(); ++yy) {
        if(get(x, yy) != startingChar) {
            break;
        }
        for(int xx = x; xx < getWidth(); ++xx) {
            char newChar = get(xx, yy);
            if(newChar != startingChar) {
                break;
            }
            dimensions.x = std::max(dimensions.xInt(), xx - x + 1);
        }
        dimensions.y = std::max(dimensions.yInt(), yy - y + 1);
    }
    return dimensions;
}