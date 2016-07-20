#ifnded _WA_H_
#define _WA_H_
#include "player.h"

class WH: public Potion {
public:
	WH();
	~WH();

	getPickedBy(Player &p);
};

#endif