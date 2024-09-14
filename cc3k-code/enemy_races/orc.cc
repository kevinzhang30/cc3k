#include "orc.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 180;
const float ATK = 30;
const float DEF = 25;
const int GOLD = rand() % 2 + 1;
const char SYMBOL = 'O';
const string RACE = "Orc";

Orc::Orc(int col, int row, Game *game) : Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD} {} // constructor

Orc::~Orc() {} // destructor

char Orc::getChar() const {
    return SYMBOL;
} // getChar

string Orc::getRace() const {
    return RACE;
} // getRace

void Orc::attack(Character * c) {
    int hit = rand() % acc;
    int damage = 0;
    if (hit == 0) {
        if (c->getRace() == "Goblin") {
            damage = ceil((100.0 / (100 + c->getDef()))*(atk)*1.5);
        } else {
            damage = ceil((100.0 / (100 + c->getDef()))*(atk));
        }
    }
    c->defend(damage);
} // attack