#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"
#include "merchanthoard.h"

class Merchant: public Enemy {
	static bool hostile
	const int defaultHP;
	const int defaultAtk;
	const int defaultDef;
	MerchantHoard merchangHoard;

public:
	Merchant();
	~Merchant();

	bool isHostile();
	void makeHostile(); // Flips the static hostile field. Must be called first time the player attacks any merchant. 
	void getAttackedBy(Character &c); // Would always be a player
	void attack(Character &c);
	void whenDead(Player &p);

};

#endif