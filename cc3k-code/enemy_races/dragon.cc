#include "dragon.h"
#include "../game.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 150;
const float ATK = 20;
const float DEF = 20;
const int GOLD = 0;
const char SYMBOL = 'D';
const string RACE = "Dragon";


Dragon::Dragon(int col, int row, Game * game, DragonHoard * hoard) : 
    Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD}, hoard{hoard} {} // constructor

Dragon::~Dragon() {} // destructor

char Dragon::getChar() const {
    return SYMBOL;
} // getChar

string Dragon::getRace() const {
    return RACE;
} // getRace

int Dragon::perish() {
    hoard->free();
    game->setCharAt(col, row, game->charAtEmpty(col, row));
    return 0;
} // perish

void Dragon::respond(Player *p) {
    int pRow = p->getRow();
    int pCol = p->getCol();
    int hRow = hoard->getRow();
    int hCol = hoard->getCol();
    if ((abs(pRow - row) <= 1 && abs(pCol - col) <= 1) || (abs(pRow - hRow) <= 1 && abs(pCol - hCol) <= 1)) {
        int initPlayerHp = p->getHp();
        this->attack(p);
        int remPlayerHp = p->getHp();
        if (initPlayerHp == remPlayerHp) {
            game->addToAction("The " + this->getRace() + " missed its attack.");
        } else {
            game->addToAction("The " + this->getRace() + " dealt " + std::to_string(initPlayerHp - remPlayerHp) + " dmg." );
        }
    }
} // respond

void Dragon::move(Direction d) {} // move
