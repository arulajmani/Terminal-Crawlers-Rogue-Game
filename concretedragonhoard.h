#ifndef _CONCDRAGHO_H_
#define _CONCDRAGHO_H_
#include "publisherdragonhoard.h"

class ConcreteDragonHoard {
	ConcreteDragonHoard();
	~ConcreteDragonHoard();
public:
	bool getState(); // To check if the player is within one step of the haord
	// Will be used in isHostile of the dragon.

};

#endif