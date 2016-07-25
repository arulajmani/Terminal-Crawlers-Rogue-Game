#include "character.h"
#include "player.h"
#include "enemy.h"
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


