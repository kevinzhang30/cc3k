#ifndef GOLD_H
#define GOLD_H

#include "player.h"

class Gold : public Item {
  int value;
  bool guarded;
  public:
    Gold(int col, int row, int value, bool guarded);
    ~Gold();
    int getValue() const;
    // included in UML
    virtual bool consumed(Player * p);
    char getChar() const;
    bool isGuarded() const;
    void free();
};

#endif
