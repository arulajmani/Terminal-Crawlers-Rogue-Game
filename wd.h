#ifndef _WD_H_
#define _WD_H_
#include "potion.h"
#include "player.h"
#include <memory>

class WD: public Potion {
public:
	WD();
	~WD();

	void getPickedBy(Player &p);
};

#endif

