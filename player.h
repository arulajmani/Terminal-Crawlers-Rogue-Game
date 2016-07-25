#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <utility> 
#include <memory>
#include "character.h"

class Gold; 
class Potion;
class Enemy;

class Player: public Character {
	std::string race;
	int levelAtk;
	int levelDef;
	int gold;
public:
	Player(std::string race, int hp, int atk, int def);
	virtual ~Player()=0;

	int getLevelAtk() const;
	int getLevelDef() const;
	int getGold() const;
	virtual double printGold(); 

	virtual bool specialAttack();
	virtual bool mustRecharge();

	void setLevelAtk(int levelAtk);
	void setLevelDef(int levelDef);
	void setGold(int value); // Perform computation in base classes, this will just update. (Allow removal of gold as well)
	
	void reset(); // Called when level is crossed, resets everything to 0.
	std::pair<int, int> checkMove(std::string direction);
	std::string getRace();
	virtual void pickItem(Gold &g);
	virtual void pickItem(Potion &p);
	virtual void attack(Enemy &e);

};

#endif
