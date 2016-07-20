#include "potion.h"


Potion::Potion(int atkChange, int defChange, int hpChange): atkChange{atkChange}, defChange{defChange}, hpChange{hpChange} {}





int Potion::getAtkChange() { return atkChange; }
int Potion::getDefChange() { return defChange; }
int Potion::getHPChange() { return hpChange; }


