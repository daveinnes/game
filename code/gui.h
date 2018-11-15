#ifndef _GUI_H_
#define _GUI_H_

#include <ncurses.h>
#include "vector.h"

class Gui
{
public:
    Gui(int x, int y, int width, int height);
    ~Gui();
    void draw();

private:
    WINDOW* mWin;
    int mWidth;
    int mHeight;
    Vector2 mPos;
};
#endif