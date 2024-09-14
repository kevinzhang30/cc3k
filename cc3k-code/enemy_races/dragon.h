#ifndef DRAGON_H
#define DRAGON_H

#include "../enemy.h"
#include "../gold_types/dragonhoard.h"

class Dragon : public Enemy {
    DragonHoard * hoard;
  public:
    Dragon(int col, int row, Game * game, DragonHoard * hoard);
    ~Dragon();
    // included in UML
    char getChar() const override;
    string getRace() const override;
    int perish() override;
    void respond(Player *p) override;
    void move(Direction d) override;
};

#endif
