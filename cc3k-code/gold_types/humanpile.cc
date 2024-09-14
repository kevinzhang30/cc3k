#include "humanpile.h"

const int VALUE = 4;

HumanPile::HumanPile(int col, int row) : Gold{col, row, VALUE, false} {} // constructor

HumanPile::~HumanPile() {} // destructor

string HumanPile::getType() const{
    return "Human";
} // getType
