#include "gui.h"

#include <string>

#include "game.h"
#include "util.h"
#include "player.h"
#include "resource.h"

Gui::Gui(int x, int y, int width, int height, int playerCount)
: mPos(Vector2(x,y))
, mWidth(width)
, mHeight(height)
, mPlayerCount(playerCount) {
    mWin = newwin(height, width, y, x);
}

Gui::~Gui() {

}

void Gui::draw() {
    wclear( mWin);

    Player* selectedPlayer = Game::get()->selectedPlayer();
    int margin = 1;
    int spacing = 2;
    int x = margin;
    int y = margin;
    for(int i = 0; i < mPlayerCount; ++i) {
        Player* player = Game::get()->player(i);

        if(selectedPlayer == player){
            wattron(mWin, COLOR_PAIR(COLOR_GREEN));
        }

        Resource* bank = player->bank();
        std::string playerStr = String::format("Player %:", i + 1);
        mvwaddstr(mWin, y, x, playerStr.c_str());
        y += spacing;

        std::string moneyStr = String::format("$: %", bank->money);
        mvwaddstr(mWin, y, x, moneyStr.c_str());
        y += spacing;

        std::string researchStr = String::format("#: %", bank->research);
        mvwaddstr(mWin, y, x, researchStr.c_str());
        y += spacing;

        std::string supplyStr = String::format("@: %/%", player->usedSupply(), player->supply());
        mvwaddstr(mWin, y, x, supplyStr.c_str());
        y += spacing;
        y += spacing;

        wattroff(mWin, COLOR_PAIR(COLOR_GREEN));
    }

    wrefresh(mWin);
}