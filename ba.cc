#include "ba.h"

const int hpDelt = 0;
const int atkDelt = 5;
const int defDelt = 0;

BA::BA():Potion(hpDelt, atkDelt, defDelt){}

BA::~BA(){}

void BA::getPickedBy(Player &p) {
	p.pickItem(*this);
}