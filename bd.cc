#include "bd.h"

const int hpDelt = 0;
const int atkDelt = 0;
const int defDelt = 5;

BD::BD():Potion(hpDelt, atkDelt, defDelt, "Boost Defence"){}

BD::~BD(){}

void BD::getPickedBy(Player &p) {
	p.pickItem(*this);
}