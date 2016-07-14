#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"
#include <string>

class Human: public Player{
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;

public:
	Human(std::string race);
	~Human();

	void getAttackedBy(Character &c);
	void attack(Character &c);
};

#endif