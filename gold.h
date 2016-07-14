#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"
#include "player.h"

class Gold: public Item{
	const int value;

public:
	Gold(int value);
	~Gold()=0;

	void getPickedBy(Player &p);
	int getValue();

};

endif