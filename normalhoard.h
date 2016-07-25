#ifndef _NORMALHOARD_H_
#define _NORMALHOARD_H_
#include "gold.h"
#include "player.h"
#include <memory>

class NormalHoard : public Gold {
	public:
		NormalHoard();
		~NormalHoard();
		void getPickedBy(Player &p);
};

#endif
