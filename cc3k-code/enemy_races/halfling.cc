#include "halfling.h"

const int ACC = 2;
const int AGL = 2;
const int HP = 100;
const float ATK = 15;
const float DEF = 20;
const int GOLD = rand() % 2 + 1;
const char SYMBOL = 'L';
const string RACE = "Halfling";

Halfling::Halfling(int col, int row, Game *game) : Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD} {} // constructor

Halfling::~Halfling() {} // destructor

char Halfling::getChar() const {
    return SYMBOL;
} // getChar

string Halfling::getRace() const {
    return RACE;
} // getRace
