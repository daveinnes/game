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
    
    Game* game = Game::create();
    game->run();
    Game::destroy();

    endwin();
}