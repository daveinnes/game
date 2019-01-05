#include <bits/stdc++.h>
#include <ncurses.h>

#include "game.h"

int main(int argc, char** argv) {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    curs_set(0);
    start_color();
    init_pair(COLOR_BLACK  , COLOR_BLACK  , COLOR_BLACK);
    init_pair(COLOR_RED    , COLOR_RED    , COLOR_BLACK);
    init_pair(COLOR_GREEN  , COLOR_GREEN  , COLOR_BLACK);
    init_pair(COLOR_YELLOW , COLOR_YELLOW , COLOR_BLACK);
    init_pair(COLOR_BLUE   , COLOR_BLUE   , COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN   , COLOR_CYAN   , COLOR_BLACK);
    init_pair(COLOR_WHITE  , COLOR_WHITE  , COLOR_BLACK);

    Game* game = Game::create();
    game->run();
    Game::destroy();

    endwin();
}