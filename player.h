#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"
#include <string>

class Gold; // Include this shit in .cc
class Potion;

class Player: public class Character {
	std::string race;
	int gold;
	int levelAtk;
	int levelDef;

public:
	Player(std::string race, int hp, int atk, int def);
	~Player()=0;

	int getLevelAtk() const;
	int getLevelDef() const;
	int getGold() const;

	void setLevelAtk(int levelAtk);
	void setLevelDef(int levelDef);
	void setGold(int value); // Perform computation in base classes, this will just update. (Allow removal of gold as well)
	
	std::string getRace();
	virtual void pickItem(Gold &g);
	virtual void pickItem(Potion &p);

};

#endif