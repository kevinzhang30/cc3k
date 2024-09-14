#include "wounddef.h"
#include "../player.h"

WD::WD(int col, int row) : Potion{col, row} {} // constructor

WD::~WD() {} // destructor

bool WD::consumed(Player *p) {
    float initDef = p->getDef();
    p->consumedPotions() = make_shared <DefPotion>(p->consumedPotions(), false, p->getMult());
    std::stringstream ss;
    ss  << "[" << p->getDef()-initDef <<" def]";
    effect = ss.str();
    return false;
} // consumed

string WD::getType() const {
    return "WD";
} // getType

