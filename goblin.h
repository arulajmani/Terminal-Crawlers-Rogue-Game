#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"


class Goblin: public Enemy {
	const NormalHoard nh;



public:
	Goblin();
	~Goblin();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);


};

#endif