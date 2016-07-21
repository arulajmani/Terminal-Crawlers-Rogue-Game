#ifndef _ITEM_H_
#define _ITEM_H_
#include "gameelement.h"
#include "player.h"

class Item {
public:
	virtual void getPickedBy(Player &p)=0;
};

#endif