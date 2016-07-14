#ifndef _ELF_H_
#define _ELF_H_

#include "player.h"
#include <string>

class Elf: public Player{
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;

public:
	Elf(std::string race);
	~Elf();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Potion &p)
};

#endif