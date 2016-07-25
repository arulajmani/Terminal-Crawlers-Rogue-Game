#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"
#include <memory>

class Goblin: public Enemy {
	NormalHoard nh;



public:
	Goblin();
	~Goblin();
	void whenDead(Player &p);


};

#endif

