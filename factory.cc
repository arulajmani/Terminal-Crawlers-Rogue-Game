#include "factory.h"

using namespace std;

Factory::Factory(){}

Factory::~Factory(){}


shared_ptr<Player> Factory::createPlayer(string race) {
	shared_ptr<Player> newPlayer = nullptr;

	if(race == "h") {
		newPlayer = make_shared<Human>();
	}
	else if(race == "e") {
		newPlayer = make_shared<Elf>();
	}
	else if(race == "o") {
		newPlayer = make_shared<Orc>();
	} 
	else if(race == "d") {
		newPlayer = make_shared<Dwarf>();
	} 
	else if (race == "c") {
		newPlayer = make_shared<Charizard>();
	}
	return newPlayer; 
}


shared_ptr<Potion> Factory::createPotion(string potionType) {
	shared_ptr<Potion> newPotion = nullptr;

	if(potionType == "rh") {
		newPotion = make_shared<RH>();
	}
	else if(potionType == "ba") {
		newPotion = make_shared<BA>();
	}
	else if(potionType == "bd") {
		newPotion = make_shared<BD>();
	}
	else if(potionType == "ph") {
		newPotion = make_shared<PH>();
	}
	else if(potionType == "wa") {
		newPotion = make_shared<WA>();
	}
	else if(potionType == "wd") {
		newPotion = make_shared<WD>();
	}
	return newPotion;	
}


shared_ptr<Enemy> Factory::createEnemy(string enemyType) {
	shared_ptr<Enemy> newEnemy = nullptr;

	if(enemyType == "m") {
		newEnemy = make_shared<Merchant>();
	}
	else if(enemyType == "p") {
		newEnemy = make_shared<Phoenix>();
	}
	else if(enemyType == "d") {
		newEnemy = make_shared<ConcreteDragon>();
	}
	else if(enemyType == "v") {
		newEnemy = make_shared<Vampire>();
	}
	else if(enemyType == "t") {
		newEnemy = make_shared<Troll>();
	}
	else if(enemyType == "g") {
		newEnemy = make_shared<Goblin>();
	} 
	else if (enemyType == "w") {
		newEnemy = make_shared<Werewolf>();
	}
	return newEnemy;
}

shared_ptr<Gold> Factory::createGold(string hoardType) {
	shared_ptr<Gold> newGold = nullptr;

	if(hoardType == "nh") {
		newGold = make_shared<NormalHoard>();
	}
	else if(hoardType == "sh") {
		newGold = make_shared<SmallHoard>();
	}
	else if(hoardType == "dh") {
		newGold = make_shared<ConcreteDragonHoard>();
	}
	else if(hoardType == "mh") {
		newGold = make_shared<MerchantHoard>();
	}

	return newGold;
}