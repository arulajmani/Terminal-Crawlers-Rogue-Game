#ifndef _BA_H_
#define _BA_H_
#include "player.h"
#include "potion.h"

class BA: public Potion {
public:
	BA();
	~BA();

	void getPickedBy(Player &p);
};

#endif