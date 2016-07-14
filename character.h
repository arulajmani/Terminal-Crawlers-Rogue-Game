#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "gameelement.h"

class Character: public GameElement {
	int hp; 
	int atk; 
	int def;

public:
	Character(int hp, int atk, int def);
	~Character();

	int getHP() const;
	int getAtk() const;
	int getDef() const;

	void setHP(int hp);
	void setAtk(int atk);
	void setDef(int def);

	virtual void getAttackedBy(Character &c)=0;
	virtual void attack(Character &c)=0;

};

#endif
