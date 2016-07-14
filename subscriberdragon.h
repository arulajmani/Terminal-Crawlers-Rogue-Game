#ifndef _SUBSDRAGON_H_
#define _SUBSDRAGON_H_
#include "enemy.h"

class SubscriberDragon: public Enemy {
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;

public:
	SubscriberDragon();
	~SubscriberDragon();

	void notify();
};

#endif