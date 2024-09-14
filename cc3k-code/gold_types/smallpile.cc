#include "smallpile.h"

const int VALUE = 1;

SmallPile::SmallPile(int col, int row) : Gold{col, row, VALUE, false} {} // constructor

SmallPile::~SmallPile() {} // destructor

string SmallPile::getType() const{
    return "Small";
} // getType
