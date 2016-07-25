#ifndef _BD_H_
#define _BD_H_
#include "player.h"
#include "potion.h"
#include <memory>

class BD: public Potion {
public:
	BD();
	~BD();

	void getPickedBy(Player &p);
};

#endif
