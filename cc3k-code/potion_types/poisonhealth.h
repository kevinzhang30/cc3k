#ifndef POISONHEALTH_H
#define POISONHEALTH_H

#include "../potion.h"

class PH : public Potion {
  public:
    PH(int col, int row);
    ~PH();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;
};

#endif
