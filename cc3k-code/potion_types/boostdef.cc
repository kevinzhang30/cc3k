#include "boostdef.h"
#include "../player.h"

BD::BD(int col, int row) : Potion{col, row} {} // constructor

BD::~BD() {} // destructor

bool BD::consumed(Player *p) {
    float initDef = p->getDef();
    p->consumedPotions() = make_shared<DefPotion>(p->consumedPotions(), true, p->getMult());
    std::stringstream ss;
    ss << "[" << p->getDef()-initDef <<" def]";
    effect = ss.str();
    return false;
} // consumed

string BD::getType() const {
    return "BD";
} // getType
