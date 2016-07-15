#include "dwarf.h"
using namespace std;

const int defaultHP = 100;
const int defaultAtk = 20;
const int defaultDef = 30;

Dwarf::Dwarf(): Player{"Dwarf", defaultHP, defaultDef, defaultAtk} {}
Dwarf::~Dwarf() {}

void Dwarf::pickItem(Gold &g) {
	int moreGold = g.getValue() * 2;
	int value = this->getGold() + moreGold;
	this->setGold(value);
}