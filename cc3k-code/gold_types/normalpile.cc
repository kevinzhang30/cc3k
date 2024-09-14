#include "normalpile.h"

const int VALUE = 2;

NormalPile::NormalPile(int col, int row) : Gold{col, row, VALUE, false} {} // constructor

NormalPile::~NormalPile() {} // destructor

string NormalPile::getType() const{
    return "Normal";
} // getType
