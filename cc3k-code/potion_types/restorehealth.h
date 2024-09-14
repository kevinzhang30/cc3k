#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H

#include "../potion.h"

class RH : public Potion {
  public:
    RH(int col, int row);
    ~RH();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;
};

#endif
