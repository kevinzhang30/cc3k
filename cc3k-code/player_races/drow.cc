#include "drow.h"

const int ACC = 1;
const int AGL = 1;
const int HP = 150;
const float ATK = 25;
const float DEF = 15;
const int GOLD = 0;
const int MAXHP = 150;
const float MULT = 1.5;


Drow::Drow(int col, int row, Game *game) : 
    Player{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD, MAXHP, MULT} {} // constructor

Drow::~Drow() {} // destructor

string Drow::getRace() const {
    return "Drow";
} // getRace

