#include "mine.h"
#include "resource.h"

Mine::Mine(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning)
:Gatherer(pos, dimensions, tuning, kChar) {

}

void Mine::deposit(Resource* bank, int amount) {
    bank->money += amount;
}

char Mine::getBuiltChar() {
    return 'm';
}