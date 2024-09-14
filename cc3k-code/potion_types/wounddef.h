#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "../potion.h"

class WD : public Potion {
  public:
    WD(int col, int row);
    ~WD();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;
};

#endif
