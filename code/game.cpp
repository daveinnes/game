#include "game.h"

#include <ctime>

#include "input.h"
#include "object.h"
#include "render.h"
#include "world.h"
#include "vector.h"
#include "util.h"
#include "player.h"
#include "gui.h"
#include "tuning.h"
#include "time.h"

Game* Game::sGame;

Game* Game::create() {
    sGame = new Game();
    sGame->init();
    return sGame;
}

Game* Game::get() {
    return sGame;
}

void Game::destroy() {
    delete sGame;
}

Game::Game() {
}

Game::~Game() {
    delete mTuning;
    delete mPlayer;
    delete mWorld;
    delete mInput;
    delete mRender;
    delete mGui;
    delete mTime;
}

void Game::init() {
    mTuning = new Tuning();
    mTuning->load("../data/tuning.json");

    mWorld = new World();
    std::string mapText = File::readText("../data/map.txt");
    mWorld->init(mapText);

    mPlayer = new Player();
    mInput = new Input();
    mRender = new Render(mWorld->getWidth(), mWorld->getHeight());
    mTime = new Time();

    int guiWidth = mTuning->get("gui")["width"].asInt();
    mGui = new Gui(mWorld->getWidth() - guiWidth, 0, mWorld->getWidth(), mWorld->getHeight());
}

void Game::run() {
    bool running = true;

    mTime->start();
    while(running) {
        mTime->startFrame();
        mInput->read();
        mPlayer->update();
        mWorld->update(mInput);
        mRender->beginFrame();
        mWorld->render(mRender);
        mRender->draw();
        mGui->draw();
        mTime->endFrame();
        if(mInput->get() == 'q') {
            running = false;
        }
    }
}
