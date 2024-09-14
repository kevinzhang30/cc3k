#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "../gold.h"

class DragonHoard : public Gold {

  public:
    DragonHoard(int col, int row);
    ~DragonHoard();
    // included in UML
    string getType() const override;
};

#endif
