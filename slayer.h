#ifndef _SLAYER_H_
#define _SLAYER_H_
#include <string>
#include "player.h"
#include "enemy.h"


class Slayer: public Player {
	char enemy;
public:
	Slayer();
	~Slayer();

	void attack(Enemy &e) override;
	void changeEnemy(char newEnemy);
};

#endif