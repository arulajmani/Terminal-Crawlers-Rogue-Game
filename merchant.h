#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"
#include "merchanthoard.h"
#include "player.h"
#include "character.h"
#include <memory>

class Merchant: public Enemy {
	static bool hostile;
	MerchantHoard merchantHoard;

public:
	Merchant();
	~Merchant();

	bool isHostile();
	void makeHostile(); // Flips the static hostile field. Must be called first time the player attacks any merchant.
	void whenDead(Player&p); 

};

#endif

