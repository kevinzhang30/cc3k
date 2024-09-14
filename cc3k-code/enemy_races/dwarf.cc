#include "dwarf.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 100;
const float ATK = 20;
const float DEF = 30;
const int GOLD = rand() % 2 + 1;
const char SYMBOL = 'W';
const string RACE = "Dwarf";

Dwarf::Dwarf(int col, int row, Game *game) : Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD} {} // constructor

Dwarf::~Dwarf() {} // destructor

char Dwarf::getChar() const {
    return SYMBOL;
} // getChar

string Dwarf::getRace() const {
    return RACE;
} // getRace