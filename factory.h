#ifndef _FACTORY_H_
#define _FACTORY_H_ // Might make sense to move all these header files to the .cc
#include <string>
#include "gameelement.h"
#include "enemy.h"
#include "werewolf.h"
#include "phoenix.h"
#include "concretedragon.h"
#include "troll.h"
#include "goblin.h"
#include "vampire.h"
#include "merchant.h"

#include "potion.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"

#include "gold.h"
#include "smallhoard.h"
#include "merchanthoard.h"
#include "normalhoard.h"
#include "concretedragonhoard.h"

#include "player.h"
#include "human.h"
#include "elf.h"
#include "orc.h"
#include "dwarf.h"


class Factory {

public:
	Factory();
	~Factory();

	std::shared_ptr<GameElement> createPlayer(std::string race);
	std::shared_ptr<GameElement> createPotion(std::string potionType);
	std::shared_ptr<GameElement> createGold(std::string hoardType);
	std::shared_ptr<GameElement> createEnemy(std::string enemyType);
	
};

#endif