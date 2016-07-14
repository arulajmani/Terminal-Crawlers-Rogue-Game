#ifndef _ORC_H_
#define _ORC_H_

#include "player.h"
#include <string>

class Orc: public Player{
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;

public:
	Orc(std::string race);
	~Orc();

	void getAttackedBy(Character &c);
	void attack(Character &c);
	void pickItem(Gold &g);

};

#endif