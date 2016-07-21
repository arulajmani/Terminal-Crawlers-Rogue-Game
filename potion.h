#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include "player.h"

class Potion: public Item{
	const int atkChange;
	const int defChange;
	const int hpChange;

public:
	Potion(const int atkChange, const int defChange, const int hpChange);
	virtual ~Potion()=0;

	int getAtkChange();
	int getDefChange();
	int getHPChange();

};

#endif