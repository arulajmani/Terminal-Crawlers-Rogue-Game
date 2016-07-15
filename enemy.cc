#include "enemy.h"

using namespace std;

Enemy::Enemy(int hp, int atk, int def): Character(hp, atk, def) {}

Enemy::~Enemy(){}

Enemy::virtual bool isHostile(){
	return true;
}





