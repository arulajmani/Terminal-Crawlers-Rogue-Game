#include "ph.h"

const int hpChange = -10;
const int atkChange = 0;
const int defChange = 0;

PH::PH():Potion(hpChange, atkChange, defChange){}

PH::~PH(){}

void PH::getPickedBy(Player &p) {
	p.pickItem(*this);
}