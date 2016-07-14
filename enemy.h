#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "player.h"
#include <string>


class Enemy: public class Character {

public:
	Enemy();
	~Enemy();

	virtual int dropGold();
	virtual bool isHostile();
	virtual void whenDead(Player &p)=0; // To force giving of contained gold in enemy
										// to player p


};

#endif