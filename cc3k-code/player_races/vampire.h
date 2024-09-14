#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../player.h"

class Vampire : public Player {
  public:
    Vampire(int col, int row, Game *game);
    ~Vampire();
    //inluded in UML
    string getRace() const override;
    void attack(Character *c) override;

};

#endif