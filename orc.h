#ifndef _ORC_H_
#define _ORC_H_
#include <memory>
#include "player.h"
#include <string>
#include "gold.h"

class Orc: public Player{
public:
	Orc();
	~Orc();

	double printGold() override;

};

#endif

