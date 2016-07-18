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
	pair <int, int> playerCoords = chamberArr[chamberNum]->placeElement();
	myPlayer->setCoords(playerCoords);
	theBoard [get<0>(playerCoords)] [get<1>(playerCoords)] = '@';
	spawnStairs(chamberNum);
}

void Floor::spawnStairs(int chamberNum) {
	int stairNum = rand() % 5;
	while(stairNum == chamberNum) {
		stairNum = rand() % 5;
	}
	pair<int, int> stairCoords = chamberArr[stairNum]->placeElement();
	theBoard [get<0>(stairCoords)] [get<1>(stairCoords)] = '\\';
	spawnPotions();
}

void Floor::spawnPotions() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int potionNum = rand() % 6;
		potionVec.emplace_back(factory.createPotion(potionType[potionNum]));

		do { // Ensure the cell chosen is empty
			pair <int, int> potionCoords = chamberArr[chamberNum]->placeElement();
		}while (theBoard [get<0>(potionCoords)] [get<1>(potionCoords)] != '.');

		potionVec.back()->setCoords(potionCoords);
		theBoard [get<0>(potionCoords)] [get<1>(potionCoords)] = 'P';
	}
	spawnGold();
}

void Floor::spawnGold() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int goldNum = rand() % 8;
		goldVec.emplace_back(factory.createGold(goldType[goldNum]));

		do { // Ensure the cell chosen is empty
			pair <int, int> goldCoords = chamberArr[chamberNum]->placeElement();
		}while (theBoard [get<0>(goldCoords)] [get<1>(goldCoordsd)] != '.');

		goldVec.back()->setCoords(goldCoords);
		theBoard [get<0>(goldCoords)] [get<1>(goldCoords)] = 'G';

		if (goldNum == 1) { // We created a dragon gold type, so we must spawn the dragon in this case!
			enemyVec.emplace_back(factory.createEnemy("d"));
			do {
				pair<int, int> dragonCoords = chamberArr[chamberNum]->placeDragon(goldCoords);
			} while( theBoard[get<0>(dragonCoords)] [get<1>(dragonCoords)] != '.');
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

		do {
			pair <int, int> enemyCoords = chamberArr[chamberNum]->placeElement();
		}while (theBoard [get<0>(enemyCoords)] [get<1>(enemyCoords)] != '.');

		enemyVec.back()->setCoords(enemyCoords);
		theBoard [get<0>(enemyCoords)] [get<1>(enemyCoords)] = enemyVec.back()->displayDisplaySymbol();
	}
}

void Floor::removePotion(pair <int, int> coords) {
	int length = potionVec.size();
	for(int i = 0; i < length; ++i) {
		if(potionVec[i]->getCoords() == coords) {
			potionVec[i].reset();
			potionVec.erase( potionVec.begin() + i ); // Remove the pointer from the vector as well.
		}
	}
}

void Floor::removeGold(pair <int, int> coords) {
	int length = goldVec.size();
	for(int i = 0; i < length; ++i) {
		if(goldVec[i]->getCoords() == coords) {
			goldVec[i].reset();
			goldVec.erase( goldVec.begin() + i ); // Remove the pointer from the vector as well.
		}
	}
}

void Floor::removeEnemy(pair <int, int> coords) {
	int length = enemyVec.size();
	for(int i = 0; i < length; ++i) {
		if(enemyVec[i]->getCoords() == coords) {
			enemyVec[i].reset();
			enemyVec.erase( enemyVec.begin() + i ); // Remove the pointer from the vector as well.
		}
	}
}

shared_ptr<Enemy> Floor::findEnemy(pair <int, int> coords) const {
	int length = enemyVec.size();
	for(int i = 0; i < length; ++i) {
		if (enemyVec[i]->getCoords() == coords) {
			return enemyVec[i];
		}
	}
	return nullptr;
}

shared_ptr<Potion> Floor::findPotion(pair <int, int> coords) const {
	int length = potionVec.size();
	for(int i = 0; i < length; ++i) {
		if (potionVec[i]->getCoords() == coords) {
			return potionVec[i];
		}
	}
	return nullptr;
}

shared_ptr<Gold> Floor::findGold(pair <int, int> coords) const {
	int length = goldVec.size();
	for(int i = 0; i < length; ++i) {
		if (goldVec[i]->getCoords() == coords) {
			return goldVec[i];
		}
	}
	return nullptr;
}

