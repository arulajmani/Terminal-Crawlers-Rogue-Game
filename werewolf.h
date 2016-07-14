#ifndef _WEREWOLF_H_
#define _WEREWOLF_H_
#include "enemy.h"
#include "normalhoard.h"


class Werewolf: public Enemy {
	const int defaultHP;
	const int defaultAt;
	const int defaultDef;
	const NormalHoard nh;



public:
	Werewolf();
	~Werewolf();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);


};

#endif