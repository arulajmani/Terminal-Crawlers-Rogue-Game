#ifndef _SUBSDRAGON_H_
#define _SUBSDRAGON_H_
#include "enemy.h"

class SubscriberDragon: public Enemy {
public:
	SubscriberDragon();
	~SubscriberDragon();

	virtual void notify()=0;
};

#endif