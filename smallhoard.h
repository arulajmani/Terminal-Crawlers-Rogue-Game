#ifndef _SMALLHOARD_H_
#define _SMALLHOARD_H_
#include "gold.h"
#include <memory>
#include "player.h"

class SmallHoard : public Gold {
	public:
		SmallHoard();
		~SmallHoard();
		void getPickedBy(Player &p);
};

#endif
