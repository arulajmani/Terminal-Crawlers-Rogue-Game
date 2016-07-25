#include "charizard.h"
#include <cmath>
using namespace std;

const int defAtk = 30;
const int defDef = 30;
const int defHP = 160;
const int specAtk = 80;

Charizard::Charizard(): Player{"Charizard", defHP, defAtk, defDef}, attackCounter{0}, spAttack{false}, recharge{false} {}
Charizard::~Charizard() {}

void Charizard::attack(Enemy &e) {
	int beforeHP = e.getHP();
	int defenderDef = e.getDef();
	if (attackCounter == 3) {
		this->setAtk(specAtk);
		spAttack = true;
	}
	if (attackCounter == 4) { // Must recharge once after special attack.
		this->setAtk(0);
		spAttack = false;
		recharge = true;
	}
	if (attackCounter == 5) { // Has recharged, set back to default attack and reset the attack counter to restart cycle.
		this->setAtk(defAtk);
		attackCounter = 0;
		recharge = false;
	}
	int attackerAtk = this->getAtk() + this->getLevelAtk();
	double damage = ceil((100.0 / ( 100.0 + static_cast<double>(defenderDef)) * static_cast<double>(attackerAtk)));
	int newHP = beforeHP - static_cast<int>(damage);
	if (newHP < 0) {
		newHP = 0;
	}
	e.setHP(newHP);
	attackCounter++;
}

bool Charizard::specialAttack() {
	return spAttack;
}

bool Charizard::mustRecharge () {
	return recharge;
}
