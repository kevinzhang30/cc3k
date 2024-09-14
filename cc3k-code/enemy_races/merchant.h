#ifndef MERCHANT_H
#define MERCHANT_H

#include "../enemy.h"
#include "../gold_types/merchanthoard.h"
#include <vector>

class Merchant : public Enemy {
    bool hostile;
    static std::vector<Merchant*> merchants;
  public:
    Merchant(int col, int row, Game * game);
    ~Merchant();
    // included in UML
    char getChar() const override;
    string getRace() const override;
    int perish() override;
    bool defend(const int &dmg) override;
    void respond(Player *p) override;
    void setHostilityToFalse();
};

#endif
