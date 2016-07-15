#ifndef _DWARF_H_
#define _DWARF_H_

#include "player.h"
#include <string>

class Dwarf: public Player{
public:
	Dwarf();
	~Dwarf();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Gold &g) override;

};

#endif