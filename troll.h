#ifndef _TROLL_H_
#define _TROLL_H_
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"
#include <memory>


class Troll: public Enemy {
	NormalHoard nh;



public:
	Troll();
	~Troll();
	void whenDead(Player &p);

};

#endif

