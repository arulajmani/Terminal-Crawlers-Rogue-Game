#include "character.h"
#include <cmath>
using namespace std; 

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def} alive{true} {}
Character::~Character() {}

int Character::getHP() const {
	return hp;
}

int Character::getAtk() const {
	return atk;
}

int Character::getDef() const {
	return def;
}

bool Character::isAlive() {
	return alive;
}



void Character::setHP(int hp) {
	this->hp = hp;
	if (hp < 0) {
		alive = false;
	}
}

void setAtk(int atk) {
	this->atk = atk;
}

void setDef(int def) {
	this->def = def;
}

virtual void attack(Character &c) {
	int beforeHP = c.getHP();
	int defenderDef = c.getDef();
	int attackerAtk = this->getAtk();
	int damage = ceil( (100 / ( 100 + defenderDef)) * attackerAtk);
	int newHP = beforeHP - damage;
	if (if newHP < 0) {
		newHP = 0;
	}
	c.setHP(newHP);
}
