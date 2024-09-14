#ifndef TROLL_H
#define TROLL_H

#include "../player.h"

class Troll : public Player {
  public:
    Troll(int col, int row, Game *game);
    ~Troll();
    //inluded in UML
    string getRace() const override;
    void consume(Item *i) override;
    void attack(Character *c) override;
    void move(Direction d) override;
};

#endif