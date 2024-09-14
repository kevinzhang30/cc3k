#ifndef ATKPOTION_H
#define ATKPOTION_H

#include "potiondecorator.h"

class AtkPotion : public PotionDecorator {
  public:
    AtkPotion(std::shared_ptr<Consumed> c, bool boost, float mult);
    // included in UML
    float getAtk() const override;
    float getDef() const override;
};


#endif