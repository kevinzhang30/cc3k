#ifndef DROW_H
#define DROW_H

#include "../player.h"

class Drow : public Player {
  public:
    Drow(int col, int row, Game *game);
    ~Drow();
    //inluded in UML
    string getRace() const override;

    

};


#endif