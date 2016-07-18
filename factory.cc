#include "factory.h"

using namespace std;

Factory::Factory(){}

Factory::~Factory(){}

Factory::createPlayer(string race) {
	shared_ptr<GameElement> newPlayer = nullptr;

	if(race == "h") {
		newPlayer = make_shared<GameElement>(new Human());
	}
	else if(race == "e") {
		newPlayer = make_shared<GameElement>(new Elf());
	}
	else if(race == "o") {
		newPlayer = make_shared<GameElement>(new Orc());
	} 
	else if(race == "d") {
		newPlayer = make_shared<GameElement>(new Dwarf());
	} 
	return newPlayer; 
}


Factory::createPotion(string potionType) {
	shared_ptr<GameElement> newPotion = nullptr;

	if(potionType == "rh") {
		newPotion = make_shared<GameElement>(new RH());
	}
	else if(potionType == "ba") {
		newPotion = make_shared<GameElement>(new BA());
	}
	else if(potionType == "bd") {
		newPotion = make_shared<GameElement>(new BD());
	}
	else if(potionType == "ph") {
		newPotion = make_shared<GameElement>(new PH());
	}
	else if(potionType == "wa") {
		newPotion = make_shared<GameElement>(new WA());
	}
	else if(potionType == "wd") {
		newPotion = make_shared<GameElement>(new WD());
	}
	return newPotion;	
}


Factory::createEnemy(string enemyType) {
	shared_ptr<GameElement> newEnemy = nullptr;

	if(enemyType == "m") {
		newEnemy = make_shared<GameElement>(new Merchant());
	}
	else if(enemyType == "p") {
		newEnemy = make_shared<GameElement>(new Phoenix());
	}
	else if(enemyType == "d") {
		newEnemy = make_shared<GameElement>(new ConcreteDragon());
	}
	else if(enemyType == "v") {
		newEnemy = make_shared<GameElement>(new Vampire());
	}
	else if(enemyType == "t") {
		newEnemy = make_shared<GameElement>(new Troll());
	}
	else if(enemyType == "g") {
		newEnemy = make_shared<GameElement>(new Goblin());
	}
	return newEnemy;
}


Factory::creaeGold(string hoardType) {
	shared_ptr<GameElement> newGold = nullptr;

	if(hoardType == "nh") {
		newGold = make_shared<GameElement>(new NormalHoard());
	}
	else if(hoardType == "sh") {
		newGold = make_shared<GameElement>(new SmallHoard());
	}
	else if(hoardType == "dh") {
		newGold = make_shared<GameElement>(new ConcreteDragonHoard());
	}
	else if(hoardType == "mh") {
		newGold = make_shared<GameElement>(new MerhcantHoard());
	}

	return newGold;
}