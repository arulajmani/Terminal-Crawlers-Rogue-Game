#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include <memory>
#include "player.h"

class Potion: public Item{
	const int atkChange;
	const int defChange;
	const int hpChange;

public:
	Potion(const int hpChange, const int atkChange, const int defChange, std::string itemName);
	virtual ~Potion()=0;

	int getAtkChange();
	int getDefChange();
	int getHPChange();

};

#endif

