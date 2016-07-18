#include "enemy.h"

using namespace std;

Enemy::Enemy(int hp, int atk, int def, char displaySymbol): Character(hp, atk, def), displaySymbol{displaySymbol} {}

Enemy::~Enemy(){}

virtual bool Enemy::isHostile(){
	return true;
}

char Enemy::displayDisplaySymbol() {
	return displaySymbol;
}




