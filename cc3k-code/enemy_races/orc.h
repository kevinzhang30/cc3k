#ifndef ORC_H
#define ORC_H

#include "../enemy.h"

class Orc : public Enemy {
  public:
    Orc(int col, int row, Game * game);
    ~Orc();
    // included in UML
    void attack(Character * c) override;
    char getChar() const override;
    string getRace() const override;
};

#endif