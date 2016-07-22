#include "enemy.h"

using namespace std;

Enemy::Enemy(int hp, int atk, int def, char displaySymbol, string enemyName): Character(hp, atk, def), displaySymbol{displaySymbol}, enemyName{enemyName} {}

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



