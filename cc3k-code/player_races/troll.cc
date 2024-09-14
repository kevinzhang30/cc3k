#include "troll.h"
#include "../game.h"

const int ACC = 1;
const int AGL = 1;
const int HP = 120;
const float ATK = 25;
const float DEF = 15;
const int GOLD = 0;
const int MAXHP = 120;
const float MULT = 1.0;
const int REGEN = 5;


Troll::Troll(int col, int row, Game *game) : 
    Player{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD, MAXHP, MULT} {} // constructor

Troll::~Troll() {} // destructor

string Troll::getRace() const {
    return "Troll";
} // getRace

void Troll::consume(Item *i) {
    i->consumed(this);
    if (i->getChar() == 'P') {
        hp = min(maxHp, hp + REGEN);
    }
} // consume

void Troll::attack(Character *c) {
    int hit = rand() % acc;
    int damage = 0;
    if (hit == 0) {
        damage = ceil((100.0 / (100 + c->getDef()))*(consumed->getAtk()));
    }
    c->defend(damage);
    hp = min(maxHp, hp + REGEN);
} // attack

void Troll::move(Direction d) {
    pair<int, int> relative = relativePosition(d);
    switch(game->getCharAt(relative.first + col, relative.second + row)) {
        case '.':
        case '+':
        case '#':
        case 'G':
        case '\\':
            col += relative.first;
            row += relative.second;
            hp = min(maxHp, hp + REGEN);
            break;
        default:
            game->addAction("Invalid Move.");
            break;
    }
} // move
