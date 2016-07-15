#include "character.h"
using namespace std; 

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def} {}
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



void Character::setHP(int hp) {
	this->hp = hp;
}

void setAtk(int atk) {
	this->atk = atk;
}

void setDef(int def) {
	this->def = def;
}

