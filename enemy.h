#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
#include <string>
#include <memory>
class Player;

class Enemy: public Character {
	char displaySymbol;
	std::string enemyName;
	bool moved;

public:
	Enemy(int hp, int atk, int def, char displaySymbol, std::string enemyName);
	~Enemy();
	virtual bool isHostile();
	virtual void whenDead(Player &p)=0; // To force giving of contained gold in enemy
										// to player p
	char displayDisplaySymbol();
	std::string getEnemyName();

	bool hasMoved(); // Returns true if the enemy has moved on current turn.
	void setMoved(bool state);

	void attack(Player &p);

};

#endif
