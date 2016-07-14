#ifndef _PHEONIX_H_
#define _PHEONIX_H_
#include "enemy.h"
#include "normalhoard.h"


class Pheonix: public Enemy {
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;
	const NormalHoard nh;



public:
	Pheonix();
	~Pheonix();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);

};

#endif