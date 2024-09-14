#include "item.h"
#include "player.h"

Item::Item(int col, int row) : col{col}, row{row} {} // constructor

Item::~Item() {} // destructor

int Item::getCol() const {
    return col;
} // getCol

int Item::getRow() const {
    return row;
} // getRow