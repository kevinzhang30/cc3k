#ifndef CHARACTER_H
#define CHARACTER_H

//#include "game.h"
#include "direction.h"
#include <cmath> // ceil
#include <stdlib.h> // srand/rand
#include <utility>
#include <string>
#include <memory>
using namespace std;

class Game;

class Character {
  protected:
	  int col, row, acc, agl, hp, gold;
    float atk, def;
	  Game * game;
  public:
    Character(int col, int row, int acc, int agl, int hp, int gold, float atk, float def, Game * game);
    ~Character();
    int getCol() const;
    int getRow() const;
    int getAgl() const;
    int getHp() const;
    virtual float getAtk() const;
    virtual float getDef() const;
    void setCol(const int c);
    void setRow(const int r);
    int getGold() const;
    // included in UML
    virtual void move(Direction d) = 0;
    virtual char getChar() const = 0;
    virtual string getRace() const = 0;
    virtual void attack(Character *c);
    virtual bool defend(const int &dmg);
    virtual void slay(Character *c);
    virtual int perish();
};


#endif
