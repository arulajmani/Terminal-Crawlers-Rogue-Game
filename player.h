#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"
#include <string>
#include <utility> 

class Gold; 
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
	
	std::pair<int, int> checkMove(std::string direction);
	std::string getRace();
	virtual void pickItem(Gold &g);
	virtual void pickItem(Potion &p);

};

#endif