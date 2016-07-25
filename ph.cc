#include "ph.h"

const int hpDelt = -10;
const int atkDelt = 0;
const int defDelt = 0;

PH::PH():Potion(hpDelt, atkDelt, defDelt, "Poison Health"){}

PH::~PH(){}

void PH::getPickedBy(Player &p) {
	p.pickItem(*this);
}
