#ifndef _PHEONIX_H_
#define _PHEONIX_H_
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"


class Phoenix: public Enemy {
	const NormalHoard nh;



public:
	Phoenix();
	~Phoenix();

	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);

};

#endif