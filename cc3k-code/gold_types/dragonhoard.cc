#include "dragonhoard.h"

const int VALUE = 6;

DragonHoard::DragonHoard(int col, int row) : Gold{col, row, VALUE, true} {} // constructor

DragonHoard::~DragonHoard() {} // destructor

string DragonHoard::getType() const{
    return "Dragon";
} // getType

