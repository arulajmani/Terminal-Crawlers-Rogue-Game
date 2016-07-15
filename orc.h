#ifndef _ORC_H_
#define _ORC_H_

#include "player.h"
#include <string>

class Orc: public Player{
public:
	Orc();
	~Orc();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Gold &g);

};

#endif