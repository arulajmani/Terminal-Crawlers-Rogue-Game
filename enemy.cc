#include "enemy.h"
#include <cmath>
#include "player.h"
#include <memory>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, char displaySymbol, string enemyName): Character(hp, atk, def), displaySymbol{displaySymbol}, enemyName{enemyName},moved{false}{}

Enemy::~Enemy(){}

bool Enemy::isHostile(){
	return true;
}

char Enemy::displayDisplaySymbol() {
	return displaySymbol;
}

string Enemy::getEnemyName() {
	return enemyName;
}

bool Enemy::hasMoved(){
	return moved;
}

void Enemy::setMoved(bool state) {
	moved = state;
}


void Enemy::attack(Player &p) {
	int beforeHP = p.getHP();
	int defenderDef = p.getDef() + p.getLevelDef();
	int attackerAtk = this->getAtk();
	double damage = ceil((100.0 / ( 100.0 + static_cast<double>(defenderDef)) * static_cast<double>(attackerAtk)));
	int newHP = beforeHP - static_cast<int>(damage);
	if (newHP < 0) {
		newHP = 0;
	}
	p.setHP(newHP);
}
