#include "potion.h"


Potion::Potion(const int atkChange, const int defChange, const int hpChange, string itemName): Item{itemName}, atkChange{atkChange}, defChange{defChange}, hpChange{hpChange} {}
Potion::~Potion(){}

int Potion::getAtkChange() { return atkChange; }
int Potion::getDefChange() { return defChange; }
int Potion::getHPChange() { return hpChange; }


