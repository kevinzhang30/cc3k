#include "potion.h"
#include "player.h"

const char pChar = 'P';

Potion::Potion(int col, int row) : Item{col, row} {} // constructor

Potion::~Potion() {} // destructor

char Potion::getChar() const {
    return pChar;
} // getChar

std::string Potion::getEffect() const {
    return effect;
}