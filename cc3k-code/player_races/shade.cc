#include "shade.h"

const int ACC = 1;
const int AGL = 1;
const int HP = 125;
const float ATK = 25;
const float DEF = 25;
const int GOLD = 0;
const int MAXHP = 125;
const float MULT = 1.0;


Shade::Shade(int col, int row, Game *game) : 
    Player{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD, MAXHP, MULT} {} // constructor

Shade::~Shade() {} // destructor

string Shade::getRace() const {
    return "Shade";
} // getRace
