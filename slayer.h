#ifndef _SLAYER_H_
#define _SLAYER_H_
#include <string>
#include "player.h"


class Slayer: public Player {
	char enemy;
public:
	Slayer();
	~Slayer();

	void attack(Character &c) override;
	void changeEnemy(char newEnemy);
};

#endif