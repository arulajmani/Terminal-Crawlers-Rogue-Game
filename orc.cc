#include "orc.h"
using namespace std;

const int defaultHP = 180;
const int defaultAtk = 30;
const int defaultDef = 25;

Orc::Orc(): Player{"Orc", defaultHP, defaultDef, defaultAtk} {}
Orc::~Orc() {}

void Orc::pickItem(Gold &g) {
	int moreGold = g.getValue() / 2;
	int value = this->getGold() + moreGold;
	this->setGold(value);
}