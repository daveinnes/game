#include "player.h"
#include "game.h"
#include "input.h"
#include "world.h"
#include "object.h"
#include "mine.h"

Player::Player() {

}
Player::~Player() {

}

void Player::update() {
    Input* input = Game::get()->input();
    if(input->get() == 'e') {
        buildMine();
    }
}

void Player::buildMine() {
    World* world = Game::get()->world();
    Object* mine = world->find<Mine>();
    mine->build();
}

