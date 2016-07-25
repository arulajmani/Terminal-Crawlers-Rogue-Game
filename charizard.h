#ifndef _CHARIZARD_H_
#define _CHARIZARD_H_
#include "player.h"
#include "enemy.h"
#include <memory>
// Every fourth attack is a specialAttack();
class Charizard: public Player {
	int attackCounter;
	bool spAttack;
	bool recharge;

public:
	Charizard();
	~Charizard();

	void attack(Enemy &e) override;
	bool specialAttack() override;
	bool mustRecharge() override;
};

#endif
