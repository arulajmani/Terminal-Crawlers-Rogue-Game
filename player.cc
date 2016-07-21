#include "player.h"
#include "potion.h"
#include "gold.h"
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

void Player::pickItem(Gold &g) {
	gold += g.getValue();
}

void Player::pickItem(Potion &p) {
	if (levelAtk + p.getAtkChange() < 0) {
		levelAtk = 0;
	} else {
		levelAtk += p.getAtkChange();
	}

	if (levelDef + p.getDefChange() < 0) {
		levelDef = 0;
	} else {
		levelDef += p.getDefChange();
	}

	int hp = this->getHP();
	hp += p.getHPChange();
	this->setHP(hp);
}


pair<int, int> Player::checkMove(string direction) {
	pair <int, int> checkCoords = this->getCoords();
	if (direction == "no") {
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += 0;
	}
	if (direction == "so") {
		get<0>(checkCoords) += -1;
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
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += -1;
	}
	if (direction == "ne") {
		get<0>(checkCoords) += 1;
		get<1>(checkCoords) += 1;
	}
	if (direction == "se") {
		get<0>(checkCoords) += -1;
		get<1>(checkCoords) += 1;
	}
	if (direction == "sw") {
		get<0>(checkCoords) += -1;
		get<1>(checkCoords) += -1;
	}
	return checkCoords;
}