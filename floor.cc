#include "floor.h"
#include <utility>
#include <string> 

using namespace std;

string potionType[6] {"rh", "ba", "bd", "ph", "wa", "wd"};
string enemyType[18] {"m", "m", "p", "p", "v", "v", "v", "t", "t", "g", "g", "g", "g", "g", "w", "w", "w", "w"};
string goldType[8] {"dh", "sh", "sh",  "nh", "nh", "nh", "nh", "nh"};


Floor::Floor(int floorNum, shared_ptr<Player> myPlayer): floorNum{floorNum}, myPlayer{myPlayer} {}
Floor::~Floor() {}

void Floor::spawnPlayer() {
	// Assuming there is an srand() before.
	int chamberNum = rand() % 5;
	chamberArr[chamberNum]->placeElement(myPlayer);
	playerChamber = chamberNum;
	pair<int, int> playerCoords = myPlayer->getCoords();
	theBoard [get<0>(playerCoords)] [get<1>(playerCoords)] = '@';
	spawnStairs(chamberNum);
}

void Floor::spawnStairs(int chamberNum) {
	int stairNum = rand() % 5;
	while(stairNum == chamberNum) {
		stairNum = rand() % 5;
	}
	pair<int, int> stairCoords = chamberArr[stairNum]->placeStairs();
 	theBoard [get<0>(stairCoords)] [get<1>(stairCoords)] = '\\';
 	spawnPotions();
}

void Floor::spawnPotions() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int potionNum = rand() % 6;
		potionArr[i] = factory.createPotion(potionType[potionNum]);
		chamberArr[chamberNum]->placeElement(potionArr[i]);
		pair<int, int> potionCoords = potionArr[i]->getCoords();
		theBoard [get<0>(potionCoords)] [get<1>(potionCoords)] = 'P';
	}
	spawnGold();
}

void Floor::spawnGold() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int goldNum = rand() % 8;
		goldArr[i] = factory.createGold(goldType[goldNum]);
		chamberArr[chamberNum]->placeElement(goldArr[i]);
		pair<int, int> goldCoords = goldArr[i]->getCoords();
		theBoard [get<0>(goldCoords)] [get<1>(goldCoords)] = 'G';

		if (goldNum == 1) { // We created a dragon gold type, so we must spawn the dragon in this case!
			enemyVec.emplace_back(factory.createEnemy("d"));
			pair<int, int> dragonCoords = chamberArr[chamberNum]->placeDragon(goldCoords);
			theBoard[get<0>(dragonCoords)] [get<1>(dragonCoords)] = 'D';
		}
	}
	spawnEnemies();
}

void Floor::spawnEnemies() {
	int moreEnemies = numEnemies - enemyVec.size(); // To account for dragons already created
	for(int i = 0; i < moreEnemies; ++i) {
		int chamberNum = rand() % 5;
		int enemyNum = rand() % 18;
		enemyVec.emplace_back(factory.createEnemy(enemyType[enemyNum]));
		chamberArr[chamberNum]->placeElement(enemyVec.back());
		pair<int, int> enemyCoords = enemyVec.back()->getCoords();
		theBoard [get<0>(enemyCoords)] [get<1>(enemyCoords)] = enemyVec.back()->displayDisplaySymbol();
	}
}