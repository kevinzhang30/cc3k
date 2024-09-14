#include "goblin.h"

const int ACC = 1;
const int AGL = 1;
const int HP = 110;
const float ATK = 15;
const float DEF = 20;
const int GOLD = 0;
const int MAXHP = 110;
const int BONUS = 5;
const float MULT = 1.0;


Goblin::Goblin(int col, int row, Game *game) : 
    Player{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD, MAXHP, MULT} {} // constructor

Goblin::~Goblin() {} // destructor

string Goblin::getRace() const {
    return "Goblin";
} // getRace

void Goblin::slay(Character *c) {
    gold += c->perish() + 5;
} // attack
