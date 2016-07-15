#ifndef _ITEM_H_
#define _ITEM_H_
#include "gameelement.h"
#include "player.h"

class Item {
public:
	virtual getPickedBy(Player &p)=0;
}