#ifnded _RH_H_
#define _RH_H_
#include "player.h"

class RH: public Potion {
public:
	RH();
	~RH();

	getPickedBy(Player &p);
};

#endif