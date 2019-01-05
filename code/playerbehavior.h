#ifndef _PLAYER_BEHAVIOR_H_
#define _PLAYER_BEHAVIOR_H_

class Player;
namespace Json {
    class Value;
}

class PlayerBehavior
{
public:
    PlayerBehavior(Player* player, const Json::Value& tuning);
    ~PlayerBehavior();

    void update();

private:
    Player* mPlayer;

    float mUpdatePeriod;
    float mLastUpdateTime;
};

#endif