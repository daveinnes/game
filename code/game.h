#ifndef _GAME_H_
#define _GAME_H_

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
    void run();

    World* world() { return mWorld; }
    Input* input() { return mInput; }
    Render* render() { return mRender; }
    Player* player() { return mPlayer; }
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
    Player* mPlayer;
    Gui* mGui;
    Tuning* mTuning;
    Time* mTime;
};
#endif