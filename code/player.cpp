#include "player.h"

#include <ncurses.h>

#include "game.h"
#include "tuning.h"
#include "resource.h"
#include "input.h"
#include "base.h"
#include "pylon.h"
#include "playerbehavior.h"

Player::Player(const Json::Value& tuning, int side)
: mSelectedBaseIndex(-1)
, mSide(side)
, mSupply(0)
, mUsedSupply(0) {
    mBank = new Resource(tuning["bank"]);
    mBehavior = new PlayerBehavior(this, tuning["behavior"]);
}

Player::~Player() {
    delete mBank;
    delete mBehavior;
}

void Player::update() {
    mBehavior->update();
}

void Player::processInput() {
    int c = Game::get()->input()->get();
    switch(c) {
        case KEY_LEFT: {
            int newindex = std::max(mSelectedBaseIndex - 1, 0);
            selectBase(newindex);
            break;
        }
        case KEY_RIGHT: {
            int newindex = std::min(mSelectedBaseIndex + 1, (int)mBases.size() - 1);
            selectBase(newindex);
            break;
        }
    }

    for(Base* base : mBases) {
        base->processInput();
    }
}

void Player::selectBase(int index) {
    if(index != mSelectedBaseIndex) {
        if(mSelectedBaseIndex > -1) {
            mBases[mSelectedBaseIndex]->select(false);
        }
        mBases[index]->select(true);
        mSelectedBaseIndex = index;
    }
}

Base* Player::selectedBase() {
    if(mSelectedBaseIndex > -1 && mSelectedBaseIndex < mBases.size()) {
        return mBases[mSelectedBaseIndex];
    }
    return nullptr;
}