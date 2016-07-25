#ifndef _PHEONIX_H_
#define _PHEONIX_H_
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"
#include <memory>

class Phoenix: public Enemy {
	NormalHoard nh;



public:
	Phoenix();
	~Phoenix();
	void whenDead(Player &p);

};

#endif

