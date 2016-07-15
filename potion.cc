#include "potion.h"


Potion::Potion(int atkChange, int defChange, int hpChange): atkChange{atkChange}, defChange{defChange}, hpChange{hpChange} {}


void getPickedBy(Player &p) {
	p.pickItem(*this);
}


int getAtkChange() { return atkChange; }
int getDefChange() { return defChange; }
int getHPChange() { return hpChange; }


