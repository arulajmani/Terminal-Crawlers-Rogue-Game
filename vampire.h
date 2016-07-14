#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "enemy.h"
#include "smallhoard.h"

class Vampire: public Enemy {
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;
	const SmallHoard smallHoard;


public:
	Vampire();
	~Vampire();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);


};

#endif