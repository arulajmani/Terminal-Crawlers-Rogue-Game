#include "wa.h"

const int hpDelt = 0;
const int atkDelt = -5;
const int defDelt = 0;

WA::WA():Potion(hpDelt, atkDelt, defDelt, "Wound Attack"){}

WA::~WA(){}

void WA::getPickedBy(Player &p) {
	p.pickItem(*this);
}

