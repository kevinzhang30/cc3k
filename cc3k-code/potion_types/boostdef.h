#ifndef BOOSTDEF_H
#define BOOSTDEF_H

#include "../potion.h"

class BD : public Potion {
  public:
    BD(int col, int row);
    ~BD();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;

};

#endif
