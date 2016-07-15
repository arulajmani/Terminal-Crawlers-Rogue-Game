#ifndef _ELF_H_
#define _ELF_H_
#include "player.h"
#include <string>

class Elf: public Player{
public:
	Elf();
	~Elf();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Potion &p) override;
};

#endif