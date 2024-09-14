#include "atkpotion.h"

const float BOOSTVALUE = 5;

AtkPotion::AtkPotion(std::shared_ptr<Consumed> c, bool boost, float mult) : PotionDecorator{c, boost, mult} {} // constructor

float AtkPotion::getAtk() const {
    if (boost) {
        return c->getAtk() + BOOSTVALUE * mult;
    } else {
        return c->getAtk() - BOOSTVALUE * mult;
    }
} // getAtk

float AtkPotion::getDef() const {
    return c->getDef();
} // getDef