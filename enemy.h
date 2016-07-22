#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "player.h"
#include <string>


class Enemy: public Character {
	char displaySymbol;
	std::string enemyName;

public:
	Enemy(int hp, int atk, int def, char displaySymbol, std::string enemyName);
	~Enemy();
	virtual bool isHostile();
	virtual void whenDead(Player &p)=0; // To force giving of contained gold in enemy
										// to player p
	char displayDisplaySymbol();
	std::string getEnemyName();

};

#endif