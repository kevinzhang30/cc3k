#include "potiondecorator.h"

PotionDecorator::PotionDecorator(std::shared_ptr<Consumed> c, bool boost, float mult) : Consumed{c->getAtk(), c->getDef()}, c{c}, boost{boost}, mult{mult} {} // constructor

PotionDecorator::~PotionDecorator() {} // destructor