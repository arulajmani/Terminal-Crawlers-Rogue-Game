#include "wa.h"

const int hpChange = 0;
const int atkChange = -5;
const int defChange = 0;

WA::WA():Potion(hpChange, atkChange, defChange, "Wound Attack"){}

WA::~WA(){}

void WA::getPickedBy(Player &p) {
	p.pickItem(*this);
}