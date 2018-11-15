#ifndef _PLAYER_H_
#define _PLAYER_H_

struct Bank {
    Bank() : money(0), research(0) {}
    int money;
    int research;
};

class Player
{
public:
    Player();
    ~Player();

    void update();
    void buildMine();
    
    Bank* bank() { return &mBank; }

private:

    Bank mBank;
};
#endif