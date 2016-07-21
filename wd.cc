#include "wd.h"

const int hpDelta = 0;
const int atkDelta = 0;
const int defDelta = -5;

WD::WD():Potion(hpDelta, atkDelta, defDelta){}

WD::~WD(){}

void WD::getPickedBy(Player &p) {
	p.pickItem(*this);
}