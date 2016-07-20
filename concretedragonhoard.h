#ifndef _CONCDRAGHO_H_
#define _CONCDRAGHO_H_
#include "publisherdragonhoard.h"
#include "player.h"

class ConcreteDragonHoard {
	ConcreteDragonHoard();
	~ConcreteDragonHoard();
public:
	void getPickedBy(Player &p);
	//bool getState(); // To check if the player is within one step of the haord
	// Will be used in isHostile of the dragon.

};

#endif