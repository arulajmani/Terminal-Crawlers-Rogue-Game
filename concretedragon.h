#ifndef _CONCDRAGON_H_
#define _CONCDRAGON_H_
#include "enemy.h"
#include "subscriberdragon.h"

class ConcreteDragonHoard;

class ConcreteDragon: public SubscriberDragon {
bool hostile;
ConcreteDragonHoard* dragonHoard;
public:
	ConcreteDragon();
	~ConcreteDragon();

	void notify(); // Sets hostile to isHostile
	bool isHostile();
};

#endif