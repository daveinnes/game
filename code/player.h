#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>

#include "game.h"

class Base;
class Resource;
class PlayerBehavior;

namespace Json {
    class Value;
}

class Player
{
public:
    Player(const Json::Value& tuning, int side);
    ~Player();

    void processInput();
    Resource* bank() { return mBank; }
    Base* base(int index) { return mBases[index]; }
    Base* selectedBase();
    void add(Base* base) { mBases.push_back(base); }
    void update();
    void selectBase(int index);
    int side() { return mSide; }

    int& usedSupply() { return mUsedSupply; }
    int& supply() { return mSupply; }
    int availableSupply() { return mSupply - mUsedSupply; }

private:

    std::vector<Base*> mBases;
    Resource* mBank;
    PlayerBehavior* mBehavior;
    int mSelectedBaseIndex;
    int mSide;
    int mUsedSupply;
    int mSupply;
};
#endif