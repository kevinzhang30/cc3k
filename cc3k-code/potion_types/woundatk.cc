#include "woundatk.h"
#include "../player.h"

WA::WA(int col, int row) : Potion{col, row} {} // constructor

WA::~WA() {} // destructor

bool WA::consumed(Player *p) {
    float initAtk = p->getAtk();
    p->consumedPotions() = make_shared <AtkPotion>(p->consumedPotions(), false, p->getMult());
    std::stringstream ss;
    ss << "[" << p->getAtk()-initAtk <<" atk]";
    effect = ss.str();
    return false;
} // consumed

string WA::getType() const {
    return "WA";
} // getType
