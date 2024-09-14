#ifndef ELF_H
#define ELF_H

#include "../enemy.h"

class Elf : public Enemy {
  public:
    Elf(int col, int row, Game * game);
    ~Elf();
    // included in UML
    void attack(Character * c) override;
    char getChar() const override;
    string getRace() const override;
};

#endif