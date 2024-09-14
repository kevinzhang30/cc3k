#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "../potion.h"

class WA : public Potion {
  public:
    WA(int col, int row);
    ~WA();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;
};

#endif
