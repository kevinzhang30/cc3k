#include "merchanthoard.h"

const int VALUE = 4;

MerchantHoard::MerchantHoard(int col, int row) : Gold{col, row, VALUE, false} {} // constructor

MerchantHoard::~MerchantHoard() {} // destructor

string MerchantHoard::getType() const{
    return "Merchant";
} // getType
