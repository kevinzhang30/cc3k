#ifndef SMALLPILE_H
#define SMALLPILE_H

#include "../gold.h"

class SmallPile : public Gold {
  public:
    SmallPile(int col, int row);
    ~SmallPile();
    // included in UML
    string getType() const override;
};

#endif