#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "potion_decorator/atkpotion.h"
#include "potion_decorator/defpotion.h"
#include <sstream>

class Potion : public Item {
  protected:
    string effect;
  public:
    Potion(int col, int row);
    ~Potion();
    // included in UML
    char getChar() const;
    std::string getEffect() const;
};


#endif