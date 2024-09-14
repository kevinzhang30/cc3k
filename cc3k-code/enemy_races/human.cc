#include "human.h"
#include "../game.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 140;
const float ATK = 20;
const float DEF = 20;
const int GOLD = 0;
const char SYMBOL = 'H';
const string RACE = "Human";

Human::Human(int col, int row, Game * game) : 
    Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD} {} // constructor

Human::~Human() {} // destructor

char Human::getChar() const {
    return SYMBOL;
} // getChar

string Human::getRace() const {
    return RACE;
} // getRace

int Human::perish() {
    std::shared_ptr<HumanPile> humanPile = std::make_shared<HumanPile>(col, row);
    game->addTreasure(humanPile, col, row);
    return 0;
} // perish
