#include "player.h"
#include "potion.h"
#include "gold.h"

Player::Player(string race, int hp, int atk, int def): Character{hp, atk, def}, race{race}, levelAtk{0}, levelDef{0} {}
Player::~Player() {}

int Player::getLevelAtk() const {
	return levelAtk;
}

int Player::getLevelDef() const {
	return levelDef;
}

int Player::getGold() const {
	return Gold;
}



void Player::setLevelDef(int levelDef) {
	this->levelDef = levelDef;
}

void Player::setLevelAtk(int levelAtk) {
	this->levelAtk = levelAtk;
}

void Player::setGold(int value) {
	this->gold = value;
}



string Player::getRace() {
	return race;
}

virtual void pickItem(Gold &g) {
	gold += g.value;
}

virtual void pickItem(Potion &p) {
	if (levelAtk + p.atkChange < 0) {
		levelAtk = 0;
	} else {
		levelAtk += p.atkChange;
	}

	if (levelDef + p.defChange < 0) {
		levelDef = 0;
	} else {
		levelDef += p.defChange;
	}

	int hp = this->getHP();
	hp += p.getHPChange();
	this->setHP(hp);
}