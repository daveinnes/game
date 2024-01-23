#include "unit.h"

#include <json/json.h>
#include <ncurses/ncurses.h>

#include "game.h"
#include "world.h"
#include "time_manager.h"
#include "assert.h"
#include "player.h"
#include "unitbehavior.h"

Unit::Unit(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c)
: Buildable(pos, dimensions, tuning, c)
, mAttackTime(0)
, mReceivedAttackTime(0)
, mSpawned(true) 
, mTarget(nullptr)
, mDead(false) {
    mHealth = tuning["health"].asFloat();
    mMaxHealth = mHealth;
    mSpeed = tuning["speed"].asFloat();
    mDamage = tuning["damage"].asFloat();
    mAttackPeriod = tuning["attackPeriod"].asFloat();
    mHitAnimationTime = tuning["hitTime"].asFloat();
    createBehavior();
}

Unit::~Unit() {
    delete mBehavior;
}

void Unit::createBehavior() {
    mBehavior = new UnitBehavior(this);
}

void Unit::startBuild() {
    Buildable::startBuild();
}

void Unit::update() {
    if(mBuilt && mSpawned && !mDead && mBehavior != nullptr) {
        mBehavior->update();
    }
    Buildable::update();
}

void Unit::attack(Unit* target) {
    mTarget = target;
    float time = Game::get()->time()->get();
    if((time - mAttackTime) > mAttackPeriod) {
        target->receiveAttack(this);
        mAttackTime = Game::get()->time()->get();
    }
}

void Unit::receiveAttack(Unit* source) {
    mReceivedAttackTime = Game::get()->time()->get();
    mHealth -= source->damage();
    if(mHealth <= 0) {
        die();
        source->target() = nullptr;
    }
}

void Unit::die() {
    mDead = true;
    Buildable::removeSupply();
}

void Unit::render(Render* render) {
    if(!mDead) {
        float time = Game::get()->time()->get();
        if(time - mReceivedAttackTime < mHitAnimationTime) {
            mChar = kHitChar;
        } else if(time - mAttackTime < mHitAnimationTime) {
            mChar = kAttackChar;
        } else {
            mChar = kChar;
        }

        float health = mHealth / mMaxHealth;
        if(health > .75f) {
            mColour = COLOR_CYAN;
        } else if(health > .5f){
            mColour = COLOR_GREEN;
        } else if(health > .25f) {
            mColour = COLOR_YELLOW;
        } else {
            mColour = COLOR_RED;
        }
        Object::render(render);
    }
}