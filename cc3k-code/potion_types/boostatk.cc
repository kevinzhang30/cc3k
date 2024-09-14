#include "boostatk.h"
#include "../player.h"

BA::BA(int col, int row) : Potion{col, row} {} // constructor

BA::~BA() {} // destructor

bool BA::consumed(Player *p) {
    float initAtk = p->getAtk();
    p->consumedPotions() = make_shared<AtkPotion>(p->consumedPotions(), true, p->getMult());
    std::stringstream ss;
    ss << "[" << p->getAtk()-initAtk << " atk]";
    effect = ss.str();
    return false;
} // consumed

string BA::getType() const {
    return "BA";
} // getType
