#include "vampire.h"

const int ACC = 1;
const int AGL = 1;
const int HP = 50;
const float ATK = 25;
const float DEF = 25;
const int GOLD = 0;
const int MAXHP = 2147483647;
const float MULT = 1.0;
const int REGEN = 5;


Vampire::Vampire(int col, int row, Game *game) : 
    Player{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD, MAXHP, MULT} {} // constructor

Vampire::~Vampire() {} // destructor

string Vampire::getRace() const {
    return "Vampire";
} // getRace

void Vampire::attack(Character *c) {
    int hit = rand() % acc;
    int damage = 0;
    if (hit == 0) {
        damage = ceil((100.0 / (100 + c->getDef()))*(consumed->getAtk()));
    }
    bool success = c->defend(damage);
    if (success) {
        if (c->getRace() == "Dwarf") {
            alterHp(-REGEN);
        } else {
            alterHp(REGEN);
        }
    }
} // attack
