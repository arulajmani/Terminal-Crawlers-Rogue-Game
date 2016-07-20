#ifnded _BD_H_
#define _BD_H_
#include "player.h"

class BD: public Potion {
public:
	BD();
	~BD();

	void getPickedBy(Player &p);
};

#endif