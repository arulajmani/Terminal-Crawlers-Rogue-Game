#include "character.h"
#include <cmath>
#include <iostream>
using namespace std; 

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}, alive{true} {}
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

bool Character::isAlive() const {
	return alive;
}

char Character::displayDisplaySymbol() {
	return '@';
}

void Character::setHP(int hp) {
	this->hp = hp;
	if (hp < 0) {
		alive = false;
	}
}

void Character::setAtk(int atk) {
	this->atk = atk;
}

void Character::setDef(int def) {
	this->def = def;
}

void Character::attack(Character &c) {
	int beforeHP = c.getHP();
	int defenderDef = c.getDef();
	int attackerAtk = this->getAtk();
	double damage = ceil((100.0 / ( 100.0 + static_cast<double>(defenderDef)) * static_cast<double>(attackerAtk)));
	int newHP = beforeHP - static_cast<int>(damage);
	if (newHP < 0) {
		newHP = 0;
	}
	c.setHP(newHP);
}
