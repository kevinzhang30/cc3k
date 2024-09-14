#include "character.h"
#include "game.h"

Character::Character(int col, int row, int acc, int agl, int hp, int gold, float atk, float def, Game * game) : 
    col{col}, row{row}, acc{acc}, agl{agl}, hp{hp}, gold{gold}, atk{atk}, def{def}, game{game} {} // Constructor

Character::~Character() {} // Destructor


int Character::getCol() const {
    return col;
} // getCol

int Character::getRow() const {
    return row;
} // getRow

int Character::getAgl() const {
    return agl;
} // getAgl

int Character::getHp() const {
    return hp;
} // getHp

float Character::getAtk() const {
    return atk;
} // getDef

float Character::getDef() const {
    return def;
} // getDef

void Character::setCol(const int c) {
    col = c;
} // setCol

void Character::setRow(const int r) {
    row = r;
} // setRow

int Character::getGold() const {
    return gold;
}

void Character::attack(Character *c) {
    int hit = rand() % acc;
    int damage = 0;
    if (hit == 0) {
        damage = ceil((100.0 / (100 + c->getDef()))*(atk));
    }
    c->defend(damage);
} // attack

bool Character::defend(const int &dmg) {
    int dodge = rand() % agl;
    if (dodge == 0) {
        hp = max(hp-dmg, 0);
        return true;
    } 
    return false;
} // defend

void Character::slay(Character *c) {
    gold += c->perish();
} // slay


int Character::perish() {
    game->setCharAt(col, row, game->charAtEmpty(col, row));
    return gold;
} // perish
