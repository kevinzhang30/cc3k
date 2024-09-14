#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "direction.h"
#include "potion.h"
#include "potion_decorator/consumed.h"
#include "potion_decorator/nopotion.h"


using namespace std;

class Item;

class Player : public Character {
  protected:
    int maxHp;
    //Consumed * consumed;
    shared_ptr<Consumed> consumed;
    float potMult;  
  public:
    Player(int col, int row, int acc, int agl, int hp, float atk, float def, Game* game, int gold, int maxHp, float potMult);
    virtual ~Player();
    float getMult() const;
    // included in UML
    virtual void consume(Item* i);
    virtual void resetEffects();
    virtual void move(Direction d) override;
    virtual char getChar() const override;
    virtual void attack(Character* c) override;
    virtual float getAtk() const override;
    virtual float getDef() const override;
    virtual void alterHp(const int& amount);
    void gain(const int& amount);
    //Consumed* 
    shared_ptr<Consumed>&consumedPotions() { return consumed; }
};


#endif
