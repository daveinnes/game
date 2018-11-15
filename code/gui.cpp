#include "gui.h"

#include <string>

#include "game.h"
#include "util.h"
#include "player.h"

Gui::Gui(int x, int y, int width, int height)
: mPos(Vector2(x,y))
, mWidth(width)
, mHeight(height) {
    mWin = newwin(height, width, y, x);
}

Gui::~Gui() {

}

void Gui::draw() {
    int margin = 1;
    int spacing = 2;
    int x = margin;
    int y = margin;
    Player* player = Game::get()->player();
    Bank* bank = player->bank();

    std::string moneyStr = String::format("$: %", bank->money);
    mvwaddstr(mWin, y, x, moneyStr.c_str());
    y += spacing;

    std::string researchStr = String::format("#: %", bank->research);
    mvwaddstr(mWin, y, x, researchStr.c_str());
    y += spacing;

    wrefresh(mWin);
}