#ifndef SHADE_H
#define SHADE_H

#include "../player.h"

class Shade : public Player {
  public:
    Shade(int col, int row, Game *game);
    ~Shade();
    //inluded in UML
    string getRace() const override;
    

};

#endif