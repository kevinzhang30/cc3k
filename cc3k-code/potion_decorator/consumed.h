#ifndef CONSUMED_H
#define CONSUMED_H

#include <memory>

class Consumed {
  protected:
    float atk, def;
  public:
    Consumed(float atk, float def);
    virtual ~Consumed() = default;
    // included in UML
    virtual float getAtk() const = 0;
    virtual float getDef() const = 0;
};


#endif