#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "enemy.h"
#include "smallhoard.h"


class Goblin: public Enemy {
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;
	const SmallHoard smallHoard;



public:
	Goblin();
	~Goblin();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);


};

#endif