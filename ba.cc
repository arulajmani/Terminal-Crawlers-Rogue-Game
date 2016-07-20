#include "ba.h"

const int hpChange = 0;
const int atkChange = 5;
const int defChange = 0;

BA::BA():Potion(hpChange, atkChange, defChange){}

BA::~BA(){}

void BA::getPickedBy(Player &p) {
	p.pickItem(*this);
}