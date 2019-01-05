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
#include "textmatrix.h"

static const char* sTuningFiles[] = {"../data/tuning2.json", "../data/tuning2.json"};

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

Game::Game()
: mRunning(false)
, mSelectedPlayer(nullptr)
, mTuningIndex(0) {
}

Game::~Game() {
    free();
}

void Game::free() {
    for(Player* player : mPlayers) {
        delete player;
    }
    mPlayers.clear();

    delete mTuning;
    mTuning = nullptr;

    delete mWorld;
    mWorld = nullptr;

    delete mInput;
    mInput = nullptr;

    delete mRender;
    mInput = nullptr;

    delete mGui;
    mGui = nullptr;

    delete mTime;
    mTime = nullptr;
}

void Game::init() {
    const char* tuningFilePath = sTuningFiles[mTuningIndex];
    mTuning = new Tuning();
    mTuning->load(tuningFilePath);

    int playerCount = mTuning->get("game")["playerCount"].asInt();
    for(int i = 0; i < playerCount; ++i) {
        int side = i == 0 ? 1 : -1;
        Player* p = new Player(mTuning->get("player"), side);
        mPlayers.push_back(p);
    }
    mSelectedPlayer = mPlayers[0];

    mWorld = new World(mTuning->get("world"));
    mInput = new Input();
    mRender = new Render(mWorld->getWidth(), mWorld->getHeight(), mTuning->get("render"));
    mTime = new Time();

    int guiWidth = mTuning->get("gui")["width"].asInt();
    mGui = new Gui(mWorld->getWidth(), 0, guiWidth, mWorld->getHeight(), playerCount);
}

void Game::reload() {
    mRender->clear();
    free();
    init();
}

void Game::run() {
    mRunning = true;
    mTime->start();
    while(mRunning) {
        mTime->startFrame();
        mInput->read();
        processInput();
        for(Player* player : mPlayers) {
            player->update();
        }
        mSelectedPlayer->processInput();
        mWorld->update();
        mRender->beginFrame();
        mWorld->render(mRender);
        mRender->draw(mTime->get());
        mGui->draw();
        mTime->endFrame();
   }
}

void Game::processInput() {
    int key = mInput->get();
    if(key == 'q') {
        mRunning = false;
    } else if(key == '\t') {
        static int playerIndex = 0;
        playerIndex = (playerIndex + 1) % 2;
        mSelectedPlayer = mPlayers[playerIndex];
    } else if(key == '\n') {
        int fileCount = sizeof(sTuningFiles) / sizeof(char*);
        mTuningIndex = (mTuningIndex + 1) % fileCount;
        reload();
    }
}
