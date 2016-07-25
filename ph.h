#ifndef _PH_H_
#define _PH_H_
#include "player.h"
#include "potion.h"
#include <memory>

class PH: public Potion {
public:
	PH();
	~PH();

	void getPickedBy(Player &p);
};

#endif
