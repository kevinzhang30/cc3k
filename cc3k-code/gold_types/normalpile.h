#ifndef NORMALPILE_H
#define NORMALPILE_H

#include "../gold.h"

class NormalPile : public Gold {
  public:
    NormalPile(int col, int row);
    ~NormalPile();
    // included in UML
    string getType() const override;
};

#endif