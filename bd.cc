#include "bd.h"

const int hpChange = 0;
const int atkChange = 0;
const int defChange = 5;

BD::BD():Potion(hpChange, atkChange, defChange){}

BD::~BD(){}

void BD::getPickedBy(Player &p) {
	p.pickItem(*this);
}