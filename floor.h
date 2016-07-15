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
	char theBoard[numRows][numCols]
	Player *myPlayer;
	Gold *goldArr[numItems];
	Potion *potionArry[numItems];
	Enemy *enemyArr[numEnemies];
	Chamber *chamberArr[numChambers];

public:
	Floor(int floorNum);
	~Floor();

	void nextState();
	void setChambers();
	void getOneChamber();

	void spawnPlayer();
	void spawnStairs(int playerChamber);
	void spawnPotions();
	void spawnGold();
	void spawnEnemies();

	void removePotion(int xcoord, int ycoord);
	void removeEnemy(int xcoord, int ycoord);
	void removeGold(int xcoord, int ycoord);

	Enemy* findEnemy(int xcoord, int ycoord) const;
	Gold* findGold(int xcoord, int ycoord) const;
	Potion* findPotion(int xcoord, int ycoord) const;
};

#endif