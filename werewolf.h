#ifndef _WEREWOLF_H_
#define _WEREWOLF_H_
#include <memory>
#include "enemy.h"
#include "normalhoard.h"
#include "player.h"
#include "character.h"


class Werewolf: public Enemy {
	NormalHoard nh;



public:
	Werewolf();
	~Werewolf();
	void whenDead(Player &p);


};

#endif

