#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "enemy.h"
#include <memory>
#include "normalhoard.h"
#include "character.h"
#include "player.h"

class Vampire: public Enemy {
	NormalHoard nh;

	
public:
	Vampire();
	~Vampire();
	void whenDead(Player &p);


};

#endif

