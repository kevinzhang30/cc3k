#include "restorehealth.h"
#include "../player.h"

const int AMOUNT = 10;

RH::RH(int col, int row) : Potion{col, row} {} // constructor

RH::~RH() {} // destructor

bool RH::consumed(Player *p) {
    int initHp = p->getHp();
    p->alterHp(ceil(AMOUNT * p->getMult()));
    effect = "[" + std::to_string(p->getHp()-initHp) +" Hp]";
    return false;
} // consumed

string RH::getType() const {
    return "RH";
} // getType