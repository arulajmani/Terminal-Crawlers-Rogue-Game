#include "slayer.h"
#include "enemy.h"
#include <cmath>
using namespace std;

const int defAtk = 25;
const int defDef = 15;
const int defHP = 150;

Slayer::Slayer(): Player {"Slayer", defHP, defAtk, defDef}, enemy {'D'} {}
Slayer::~Slayer() {}

void Slayer::attack(Enemy &e) {
	if (e.displayDisplaySymbol() == enemy) { // Special case
		e.setHP(0);
	} else { // Default behaviour.
		int beforeHP = e.getHP();
		int defenderDef = e.getDef();
		int attackerAtk = this->getAtk() + this->getLevelAtk();
		double damage = ceil((100.0 / ( 100.0 + static_cast<double>(defenderDef)) * static_cast<double>(attackerAtk)));
		int newHP = beforeHP - static_cast<int>(damage);
		if (newHP < 0) {
			newHP = 0;
		}
		e.setHP(newHP);
	}

}

void Slayer::changeEnemy(char newEnemy) {
	enemy = newEnemy;
}

