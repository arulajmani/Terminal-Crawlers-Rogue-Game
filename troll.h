#ifndef _TROLL_H_
#define _TROLL_H_
#include "enemy.h"
#include "normalhoard.h"


class Troll: public Enemy {
	const NormalHoard nh;



public:
	Troll();
	~Troll();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);

};

#endif