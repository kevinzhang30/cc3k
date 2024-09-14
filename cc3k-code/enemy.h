#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"

using namespace std;


class Enemy : public Character {
  public:
    Enemy(int col, int row, int acc, int agl, int hp, float atk, float def, Game * game, int gold);
    ~Enemy();
    // included in UML
	virtual void move(Direction d = Direction::random) override;
	virtual void respond(Player *p);
};


#endif
