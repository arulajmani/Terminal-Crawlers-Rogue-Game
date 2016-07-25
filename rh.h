#ifndef _RH_H_
#define _RH_H_
#include "player.h"
#include <memory>
#include "potion.h"

class RH: public Potion {
public:
	RH();
	~RH();

	void getPickedBy(Player &p);
};

#endif

