#ifndef HALFLING_H
#define HALFLING_H

#include "../enemy.h"

class Halfling : public Enemy {
  public:
    Halfling(int col, int row, Game * game);
    ~Halfling();
    // included in UML
    char getChar() const override;
    string getRace() const override;
};

#endif