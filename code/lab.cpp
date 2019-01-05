#include "lab.h"
#include "resource.h"

Lab::Lab(const Vector2& pos, const Vector2& dimensions, const Json::Value& tuning)
:Gatherer(pos, dimensions, tuning, kChar) {

}

void Lab::deposit(Resource* bank, int amount) {
    bank->research += amount;
}

char Lab::getBuiltChar() {
    return 'r';
}