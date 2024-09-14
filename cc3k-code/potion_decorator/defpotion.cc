#include "defpotion.h"

const float BOOSTVALUE = 5;

DefPotion::DefPotion(std::shared_ptr<Consumed> c, bool boost, float mult) : PotionDecorator{c, boost, mult} {} // constructor

float DefPotion::getAtk() const {
    return c->getAtk();
} // getAtk

float DefPotion::getDef() const {
    if (boost) {
        return c->getDef() + mult * BOOSTVALUE;
    } else {
        return c->getDef() - mult * BOOSTVALUE;
    }

} // getDef