#ifndef _ELF_H_
#define _ELF_H_
#include "player.h"
#include <string>
#include "potion.h"
#include <memory>


class Elf: public Player{
public:
	Elf();
	~Elf();

	void pickItem(Potion &p) override;
};

#endif
