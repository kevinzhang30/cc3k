#ifndef MERCHANTHOARD_H
#define MERCHANTHOARD_H

#include "../gold.h"

class MerchantHoard : public Gold {
  public:
    MerchantHoard(int col, int row);
    ~MerchantHoard();
    // included in UML
    string getType() const override;
};

#endif
