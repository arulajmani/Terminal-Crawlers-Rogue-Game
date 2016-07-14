#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include "player.h"

class Potion: public Item{
	const int atkChange;
	const int defChange;
	const int hpChange;

public:
	Potion(int atkChange, int defChange, int hpChange);
	~Potion()=0;

	void getPickedBy(Player &p);
};

endif