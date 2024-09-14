#include "gold.h"

const char gChar = 'G';

Gold::Gold(int col, int row, int value, bool guarded) : Item{col, row}, value{value}, guarded{guarded} {} // constructor

Gold::~Gold() {} // destructor

bool Gold::consumed(Player * p) {
    p->gain(value);
    return false;
} // consumed

char Gold::getChar() const {
    return gChar;
} // getChar

int Gold::getValue() const {
    return value;
} // getValue

bool Gold::isGuarded() const {
    return guarded;
} // isGuarded

void Gold::free() {
    guarded = false;
} // free