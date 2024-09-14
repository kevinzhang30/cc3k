#ifndef ITEM_H
#define ITEM_H


#include <string>
using namespace std;

class Player;

class Item {
  protected:
    int col, row;
  public:
    Item(int col, int row);
    ~Item();
    // included in UML
    virtual bool consumed(Player * p) = 0;
    int getCol() const;
    int getRow() const;
    virtual char getChar() const = 0;
    virtual string getType() const = 0;
};


#endif
