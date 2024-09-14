#ifndef GOBLIN_H
#define GOBLIN_H

#include "../player.h"

class Goblin : public Player {
  public:
    Goblin(int col, int row, Game *game);
    ~Goblin();
    //inluded in UML
    string getRace() const override;
    void slay(Character *c) override;
};

#endif