#include "elf.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 140;
const float ATK = 30;
const float DEF = 10;
const int GOLD = rand() % 2 + 1;
const char SYMBOL = 'E';
const string RACE = "Elf";

Elf::Elf(int col, int row, Game *game) : Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD} {} // constructor

Elf::~Elf() {} // destructor

char Elf::getChar() const {
    return SYMBOL;
} // getChar

string Elf::getRace() const {
    return RACE;
} // getRace

void Elf::attack(Character * c) {
    for (int i = 0; i < 2; ++i) {
        int hit = rand() % acc;
            int damage = 0;
        if (hit == 0) {
            damage = ceil((100.0 / (100 + c->getDef()))*(atk));
        }
        c->defend(damage);
        if (c->getRace() == "Drow") break;
    }
} // attack