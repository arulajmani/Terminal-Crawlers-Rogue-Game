#ifndef _ITEM_H_
#define _ITEM_H_
#include "gameelement.h"
#include "player.h"
#include <memory>

class Item:public GameElement {
	std::string itemName;
public:
	Item(std::string name);
	~Item();
	virtual void getPickedBy(Player &p)=0;
	std::string getItemName();
};

#endif
