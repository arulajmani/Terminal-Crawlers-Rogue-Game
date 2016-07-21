#ifndef _WA_H_
#define _WA_H_
#include "potion.h"
#include "player.h"

class WA: public Potion {
public:
	WA();
	~WA();

	void getPickedBy(Player &p);
};

#endif