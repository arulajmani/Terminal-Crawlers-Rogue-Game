#include "potion.h"


Potion::Potion(const int atkChange, const int defChange, const int hpChange): atkChange{atkChange}, defChange{defChange}, hpChange{hpChange} {}
Potion::~Potion(){}

int Potion::getAtkChange() { return atkChange; }
int Potion::getDefChange() { return defChange; }
int Potion::getHPChange() { return hpChange; }


