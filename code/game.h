#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

class World;
class Input;
class Render;
class Player;
class Gui;
class Tuning;
class Time;

class Game
{
public:
    static Game* create();
    static Game* get();
    static void destroy();

    void init();
    void free();
    void reload();
    void run();
    void processInput();

    World* world() { return mWorld; }
    Input* input() { return mInput; }
    Render* render() { return mRender; }
    Player* selectedPlayer() { return mSelectedPlayer; }
    Player* player(int index) { return mPlayers[index]; }
    Gui* gui() { return mGui; }
    Tuning* tuning() { return mTuning; }
    Time* time() { return mTime; }

private:
    Game();
    ~Game();

    static Game* sGame;
    World* mWorld;
    Input* mInput;
    Render* mRender;
    std::vector<Player*> mPlayers;
    Gui* mGui;
    Tuning* mTuning;
    Time* mTime;
    int mTuningIndex;

    bool mRunning;
    Player* mSelectedPlayer;
};
#endif