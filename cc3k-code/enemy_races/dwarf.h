#ifndef DWARF_H
#define DWARF_H

#include "../enemy.h"

class Dwarf : public Enemy {
  public:
    Dwarf(int col, int row, Game * game);
    ~Dwarf();
    // included in UML
    char getChar() const override;
    string getRace() const override;
};

#endif
