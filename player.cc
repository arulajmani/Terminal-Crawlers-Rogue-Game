#include "player.h"
#include "potion.h"
#include "gold.h"
#include "enemy.h"
#include <cmath>
using namespace std;

Player::Player(string race, int hp, int atk, int def): Character{hp, atk, def}, race{race}, levelAtk{0}, levelDef{0}, gold{0} {}
Player::~Player() {}

int Player::getLevelAtk() const {
	return levelAtk;
}

int Player::getLevelDef() const {
	return levelDef;
}

int Player::getGold() const {
	return gold;
}

bool Player::specialAttack() {
	return false;
}

bool Player::mustRecharge() {
	return false;
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

double Player::printGold() {
	double value = static_cast<double>(gold);
	return value;
}



string Player::getRace() {
	return race;
}

void Player::pickItem(Gold &g) {
	gold += g.getValue();
}

void Player::pickItem(Potion &p) {
	if (this->getAtk() + p.getAtkChange() < 0) {
		levelAtk = 0;
	} else {
		levelAtk += p.getAtkChange();
	}

	if (this->getDef() + p.getDefChange() < 0) {
		levelDef = 0;
	} else {
		levelDef += p.getDefChange();
	}

	int hp = this->getHP();
	hp += p.getHPChange();
	this->setHP(hp);
}

void Player::reset() {
	levelDef = 0;
	levelAtk = 0;
}


pair<int, int> Player::checkMove(string direction) {
	pair <int, int> checkCoords = this->getCoords();
	if (direction == "no") {
		get<0>(checkCoords) += -1;
		get<1>(checkCoords) += 0;
	}
	if (direction == "so") {
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += 0;
	}
	if (direction == "ea") {
		get<0>(checkCoords) += 0;
		get<1>(checkCoords) += 1;
	}
	if (direction == "we") {
		get<0>(checkCoords) += 0;
		get<1>(checkCoords) += -1;
	}
	if (direction == "nw") {
		get<0>(checkCoords) += -1;
		get<1>(checkCoords) += -1;
	}
	if (direction == "ne") {
		get<0>(checkCoords) += -1;
		get<1>(checkCoords) += 1;
	}
	if (direction == "se") {
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += 1;
	}
	if (direction == "sw") {
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += -1;
	}
	return checkCoords;
}

void Player::attack(Enemy &e) {
	int beforeHP = e.getHP();
	int defenderDef = e.getDef();
	int attackerAtk = this->getAtk() + this->getLevelDef();
	double damage = ceil((100.0 / ( 100.0 + static_cast<double>(defenderDef)) * static_cast<double>(attackerAtk)));
	int newHP = beforeHP - static_cast<int>(damage);
	if (newHP < 0) {
		newHP = 0;
	}
	e.setHP(newHP);
}

