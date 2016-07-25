#ifndef _MERCHANTHOARD_H_
#define _MERCHANTHOARD_H_
#include <memory>
#include "gold.h"
#include "player.h"

class MerchantHoard : public Gold {
	public:
		MerchantHoard();
		~MerchantHoard();
		void getPickedBy(Player &p);
};

#endif

