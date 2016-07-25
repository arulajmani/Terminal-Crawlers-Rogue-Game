#ifndef _SUBSDRAGON_H_
#define _SUBSDRAGON_H_
#include "enemy.h"
#include <memory>

class SubscriberDragon: public Enemy {
public:
	SubscriberDragon(int hp, int atk, int def);
	~SubscriberDragon();

	virtual void notify(bool dragonHostile)=0;
};

#endif

