#include "rh.h"

const int hpDelt = 10;
const int atkDelt = 0;
const int defDelt = 0;

RH::RH():Potion(hpDelt, atkDelt, defDelt, "Restore Health"){}

RH::~RH(){}

void RH::getPickedBy(Player &p) {
	p.pickItem(*this);
}

