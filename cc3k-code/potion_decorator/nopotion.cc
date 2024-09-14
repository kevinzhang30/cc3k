#include "nopotion.h"

NoPotion::NoPotion(float atk, float def) : Consumed{atk, def} {} // constructor

float NoPotion::getAtk() const {
    return atk;
} // getAtk

float NoPotion::getDef() const {
    return def;
} // getDef
