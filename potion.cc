#include "potion.h"
using namespace std;


Potion::Potion(const int hpChange, const int atkChange, const int defChange, string itemName): Item{itemName}, atkChange{atkChange}, defChange{defChange}, hpChange{hpChange} {}
Potion::~Potion(){}

int Potion::getAtkChange() { return atkChange; }
int Potion::getDefChange() { return defChange; }
int Potion::getHPChange() { return hpChange; }


