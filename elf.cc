#include "elf.h"
using namespace std;

const int defaultHP = 140;
const int defaultAtk = 30;
const int defaultDef = 10;

Elf::Elf(): Player{"Elf", defaultHP, defaultDef, defaultAtk} {}
Elf::~Elf() {}

void Elf::pickItem(Potion &p) override {
	if (p.getAtkChange() < 0) { // Reverse effect if it was negative (make it position)
		int levelAtk = this->getLevelAtk() - p.getAtkChange();
		this->setLevelAtk(levelAtk);
	} else {
		int levelAtk = this->getLevelAtk() + p.getAtkChange();
		this->setLevelAtk(levelAtk);
	}

	if(p.getDefChange() < 0) {
		int levelDef = this->getLevelDef() - p.getDefChange();
		this->setLevelDef(levelDef);
	} else {
		int levelDef = this->getLevelDef() + p.getDefChange();
		this->setLevelDef(levelDef);
	}

	if(p.getHPChange() < 0) {
		int hp = this->getHP() - p.getHPChange();
		this->setHP(hp);
	} else {
		int hp = this->getHP() + p.getHPChange();
		this->setHP(hp);
	}
}