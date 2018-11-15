#include "input.h"
#include <ncurses.h>

Input::Input() {
    mInputChar = -1;
}

void Input::read() {
    mInputChar = getch();
}

char Input::get() {
    return mInputChar;
}
