#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "gameelement.h"

class Character: public GameElement {
	int hp; 
	int atk; 
	int def;
	bool alive;

public:
	Character(int hp, int atk, int def);
	virtual ~Character() = 0;

	int getHP() const;
	int getAtk() const;
	int getDef() const;
	bool isAlive() const;

	void setHP(int hp);
	void setAtk(int atk);
	void setDef(int def);

	virtual void attack(Character &c);

};

#endif
