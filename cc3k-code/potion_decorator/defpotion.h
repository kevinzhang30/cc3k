#ifndef DEFPOTION_H
#define DEFPOTION_H

#include "potiondecorator.h"

class DefPotion : public PotionDecorator {
  public:
    DefPotion(std::shared_ptr<Consumed> c, bool boost, float mult);
    // included in UML
    float getAtk() const override;
    float getDef() const override;
};


#endif