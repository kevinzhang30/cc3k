#ifndef BOOSTATK_H
#define BOOSTATK_H

#include "../potion.h"

class BA : public Potion {
  public:
    BA(int col, int row);
    ~BA();
    // included in UML
    bool consumed(Player * p) override;
    string getType() const override;
};

#endif
