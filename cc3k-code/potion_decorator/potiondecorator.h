#ifndef POTIONDECORATOR_H
#define POTIONDECORATOR_H

#include "consumed.h"

class PotionDecorator : public Consumed {
  protected:
    std::shared_ptr<Consumed> c;
    bool boost;
    float mult;
  public:
    PotionDecorator(std::shared_ptr<Consumed> c, bool boost, float mult);
    virtual ~PotionDecorator();

};

#endif