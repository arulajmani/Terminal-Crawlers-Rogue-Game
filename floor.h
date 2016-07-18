#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "enemies.h"
#include "chamber.h"
#include <vector>
#include "factory.h"

const int displayRows = 5;
const int numRows = 25
const int numCols = 79;
const int numItems = 10;
const int numEnemies = 20;
const int numChambers = 5;

class Floor {
	const int floorNum;
	char theBoard[numRows][numCols];
	Factory factory;

	std::shared_ptr<Player> myPlayer;
	std::vector <std::shared_ptr<Gold>> goldVec;
	std::vector <std::shared_ptr<Potion>> potionVec;
	std::vector <std::shared_ptr<Enemy>> enemyVec;
	std::shared_ptr<Chamber> chamberArr[numChambers];

public:
	Floor(int floorNum, std::shared_ptr<Player> myPlayer);
	~Floor();

	void nextState();
	void setChambers();
	void getOneChamber();

	void spawnPlayer();
	void spawnStairs(int playerChamber);
	void spawnPotion();
	void spawnGold();
	void spawnEnemies();

	void removePotion(std::pair <int, int> coords);
	void removeEnemy(std::pair <int, int> coords);
	void removeGold(std::pair <int, int> coords);

	std::shared_ptr<Enemy> findEnemy(std::pair <int, int> coords) const;
	std::shared_ptr<Gold> findGold(std::pair <int, int> coords) const;
	std::shared_ptr<Potion> findPotion(std::pair <int, int> coords) const;
};

#endif