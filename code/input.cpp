#include "input.h"
#include <ncurses.h>

Input::Input()
: mInputValue(0) {
}

void Input::read() {
    mInputValue = getch();
}

int Input::get() {
    return mInputValue;
}
