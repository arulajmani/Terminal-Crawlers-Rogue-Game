#ifndef _DWARF_H_
#define _DWARF_H_

#include "player.h"
#include <string>

class Dwarf: public Player{
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;

public:
	Dwarf(std::string race);
	~Dwarf();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Gold &g);

};

#endif