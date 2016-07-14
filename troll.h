#ifndef _TROLL_H_
#define _TROLL_H_
#include "enemy.h"
#include "smallhoard.h"


class Troll: public Enemy {
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;
	const SmallHoard smallHoard;



public:
	Troll();
	~Troll();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);

};

#endif