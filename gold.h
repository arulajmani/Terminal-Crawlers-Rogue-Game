#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"
#include "player.h"
#include <memory>

class Gold: public Item{
	const int value;

public:
	Gold(int value, std::string itemName);
	virtual ~Gold()=0;

	int getValue();
	virtual bool canPickup(); 
	virtual char goldType();

};

#endif