#ifndef _UNIT_H_
#define _UNIT_H_

#include "buildable.h"
#include "object.h"

class UnitBehavior;

class Unit : public Buildable
{
friend class UnitBehavior;
public:
    static const int kType = 'unit';
    static const char kChar = 'o';
    static const char kHitChar = 'x';
    static const char kAttackChar = 'o';

    Unit(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning, char c);
    virtual ~Unit();

    virtual void attack(Unit* target);
    virtual void receiveAttack(Unit* source);
    virtual void die();
    virtual void createBehavior();
    
    bool isDead() { return mDead; }
    float percentHealth() { return mHealth / mMaxHealth; }
    float& health() { return mHealth; }
    float damage() { return mDamage; }
    Unit*& target() { return mTarget; }
    bool& spawned() { return mSpawned; }

    //Buildable
    void startBuild() override;

    //Object
    void update() override;
    void render(Render* render) override;
    bool implementsType(int type) override { return type == kType || Buildable::implementsType(type); }
    int getType() override { return kType; }

private:
    float mMaxHealth;
    float mHealth;
    float mSpeed;
    float mDamage;
    float mAttackPeriod;

    Unit* mTarget;
    UnitBehavior* mBehavior;
    bool mSpawned;
    bool mDead;
    float mAttackTime;
    float mReceivedAttackTime;
    float mHitAnimationTime;
};

#endif