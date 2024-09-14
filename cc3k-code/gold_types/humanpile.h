#ifndef HUMANPILE_H
#define HUMANPILE_H

#include "../gold.h"

class HumanPile : public Gold {
  public:
    HumanPile(int col, int row);
    ~HumanPile();
    // included in UML
    string getType() const override;
};

#endif