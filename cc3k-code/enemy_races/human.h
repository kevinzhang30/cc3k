#ifndef HUMAN_H
#define HUMAN_H

#include "../enemy.h"
#include "../gold_types/humanpile.h"

class Human : public Enemy {
  public:
    Human(int col, int row, Game * game);
    ~Human();
    // included in UML
    char getChar() const override;
    string getRace() const override;
    int perish() override;
};

#endif
