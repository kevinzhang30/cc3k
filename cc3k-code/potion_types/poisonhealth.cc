#include "poisonhealth.h"
#include "../player.h"

const int AMOUNT = -10;

PH::PH(int col, int row) : Potion{col, row} {} // constructor

PH::~PH() {} // destructor

bool PH::consumed(Player *p) {
    int initHp = p->getHp();
    p->alterHp(ceil(AMOUNT * p->getMult()));
    effect = "[" + std::to_string(p->getHp()-initHp) +" Hp]";
    if(p->getHp() == 0) {
        return true;
    }
    return false;
} // consumed

string PH::getType() const {
    return "PH";
} // getType
