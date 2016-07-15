#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"
#include <string>

class Human: public Player{
public:
	Human();
	~Human();

	void getAttackedBy(Character &c);
	void attack(Character &c);
};

#endif