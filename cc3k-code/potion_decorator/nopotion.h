#ifndef NOPOTION_H
#define NOPOTION_H

#include "consumed.h"

class NoPotion : public Consumed {
  public:
    NoPotion(float atk, float def);
    ~NoPotion() override = default;
    // included in UML
    float getAtk() const override;
    float getDef() const override;
};


#endif