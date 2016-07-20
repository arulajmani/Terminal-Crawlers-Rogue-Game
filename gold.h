#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"
#include "player.h"

class Gold: public Item{
	const int value;

public:
	Gold(int value);
	~Gold()=0;

	int getValue();
	virtual bool canPickup(); 

};

#endif