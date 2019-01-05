#ifndef _TEXTMATRIX_H_H
#define _TEXTMATRIX_H_H

#include <string>
#include "vector.h"

class TextMatrix
{
public:
    TextMatrix(const char* path);
    ~TextMatrix();
    
    void load(const char* path);
    int getWidth() const { return mWidth; }
    int getHeight() const { return mHeight; }
    char get(int x, int y) const;
    char flip();
    Vector2 getDimensions(int x, int y) const;

private:
    int mWidth;
    int mHeight;
    std::string mText;
};

#endif