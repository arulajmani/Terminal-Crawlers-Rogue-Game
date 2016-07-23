#ifndef _CONCDRAGON_H_
#define _CONCDRAGON_H_
#include "enemy.h"
#include "subscriberdragon.h"

class ConcreteDragonHoard;

class ConcreteDragon: public SubscriberDragon {
bool hostile;
std::shared_ptr<ConcreteDragonHoard> dragonHoard;
public:
	ConcreteDragon();
	~ConcreteDragon();
	void whenDead(Player &p);
	void notify(bool dragonHostile); // Sets hostile to isHostile
	bool isHostile();
	void attachHoard(std::shared_ptr<ConcreteDragonHoard> concDragonHoard);
};

#endif