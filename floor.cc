#include "floor.h"
#include <utility>
#include <string> 
#include <sstream>
#include <fstream>
#include "chamber.h"
#include "view.h"
#include <iostream>

// Gold picked and Enemy attacked and enemy attacking descriptions have to be done. 

using namespace std;

string potionType[6] {"rh", "ba", "bd", "ph", "wa", "wd"};
string enemyType[18] {"m", "m", "p", "p", "v", "v", "v", "t", "t", "g", "g", "g", "g", "g", "w", "w", "w", "w"};
string goldType[8] {"dh", "sh", "sh",  "nh", "nh", "nh", "nh", "nh"};
char allEnemies[7] = {'M', 'X', 'V', 'T', 'N', 'W', 'D'};


void Floor::recursiveChamber(int xcoord, int ycoord, shared_ptr<Chamber> newChamber, bool checkedGrid[numRows][numCols]) {

	if(xcoord < 0 || ycoord < 0 || xcoord >= numRows || ycoord >= numCols) {return;}

	checkedGrid[xcoord][ycoord] = true;
	pair<int, int> validChamCoords {xcoord, ycoord};
	if(defaultGrid[xcoord][ycoord] == '.') {
		newChamber->addCoords(validChamCoords);
	}
	if(defaultGrid[xcoord + 1][ycoord] == '.' && checkedGrid[xcoord + 1][ycoord] ==  false) {
		recursiveChamber(xcoord + 1, ycoord, newChamber, checkedGrid);
	}
	if(defaultGrid[xcoord - 1][ycoord] == '.' && checkedGrid[xcoord - 1][ycoord] == false) {
		recursiveChamber(xcoord - 1, ycoord, newChamber, checkedGrid);
	}
	if(defaultGrid[xcoord][ycoord + 1] == '.' && checkedGrid[xcoord][ycoord + 1] == false) {
		recursiveChamber(xcoord, ycoord + 1, newChamber, checkedGrid);
	}
	if(defaultGrid[xcoord][ycoord - 1] == '.' && checkedGrid[xcoord][ycoord - 1] == false) {
		recursiveChamber(xcoord, ycoord - 1, newChamber, checkedGrid);
	}

}

void Floor::makeChamber() {
	int chamberNum = 1;
	vector<pair<int, int>> v;
	bool checkedGrid[numRows][numCols] = {{ false }};
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			v.clear();
			if(defaultGrid[i][j] == '.' && checkedGrid[i][j] == false) {
				shared_ptr<Chamber> newChamber;
				newChamber = make_shared<Chamber>(chamberNum, v);
				recursiveChamber(i, j, newChamber, checkedGrid);
				chamberVec.emplace_back(newChamber);
				++chamberNum;
				checkedGrid[i][j] = true;
			}
			checkedGrid[i][j] = true;
		}
	}
}



Floor::Floor(int floorNum, shared_ptr<Player> myPlayer, bool filePresent, string floorPlan, shared_ptr<View> view): floorNum{floorNum}, myPlayer{myPlayer}, filePresent {filePresent}, floorPlan{floorPlan}, view{view}{
	try {
		ifstream f{floorPlan};
		f.exceptions(ios::failbit|ios::eofbit);
		int startRead = (floorNum - 1) * numRows;
		for (int i = 0; i < startRead; ++i) {
			string discard;
			getline(f, discard);
		}
		for(int i = 0; i < numRows; ++i) {
			string row;
			getline(f, row);
			for(int j = 0; j < numCols; ++j) {
				defaultGrid[i][j] = row[j];
				char curr = row[j];
				theBoard[i][j] = curr;
				pair <int, int> currCoords{i, j};
				if (curr == '@') {
					myPlayer->setCoords(currCoords);
					defaultGrid[i][j] = '.';
				}
				else if(curr == 'M') {
					auto merchant = factory.createEnemy("m");
					merchant->setCoords(currCoords);
					enemyVec.emplace_back(merchant);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'X') {
					auto phoenix = factory.createEnemy("p");
					phoenix->setCoords(currCoords);
					enemyVec.emplace_back(phoenix);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'W') {
					auto wwolf = factory.createEnemy("w");
					wwolf->setCoords(currCoords);
					enemyVec.emplace_back(wwolf);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'T') {
					auto troll = factory.createEnemy("t");
					troll->setCoords(currCoords);
					enemyVec.emplace_back(troll);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'V') {
					auto twilight = factory.createEnemy("v");
					twilight->setCoords(currCoords);
					enemyVec.emplace_back(twilight);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'N') {
					auto osbourne = factory.createEnemy("g");
					osbourne->setCoords(currCoords);
					enemyVec.emplace_back(osbourne);
					defaultGrid[i][j] = '.';
				}
				else if (curr == 'D') {
					auto eragon = factory.createEnemy("d");
					eragon->setCoords(currCoords);
					enemyVec.emplace_back(eragon);
					defaultGrid[i][j] = '.';
				}
				else if (curr == '0') {
					auto potion = factory.createPotion("rh");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'P'; // Must be displayed as P
				}
				else if (curr == '1') {
					auto potion = factory.createPotion("ba");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					theBoard[i][j] = 'P'; // Must be displayed as P
					defaultGrid[i][j] = '.';
				}
				else if (curr == '2') {
					auto potion = factory.createPotion("bd");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'P'; // Must be displayed as P
				}
				else if (curr == '3') {
					auto potion = factory.createPotion("ph");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'P'; // Must be displayed as P
				}
				else if (curr == '4') {
					auto potion = factory.createPotion("wa");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'P'; // Must be displayed as P
				}
				else if (curr == '5') {
					auto potion = factory.createPotion("wd");
					potion->setCoords(currCoords);
					potionVec.emplace_back(potion);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'P'; // Must be displayed as P
				}
				else if (curr == '6') {
					auto gold = factory.createGold("nh");
					gold->setCoords(currCoords);
					goldVec.emplace_back(gold);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'G'; // Must be displayed as P
				}
				else if (curr == '7') {
					auto gold = factory.createGold("sh");
					gold->setCoords(currCoords);
					goldVec.emplace_back(gold);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'G'; // Must be displayed as P
				}
				else if (curr == '8') {
					auto gold = factory.createGold("mh");
					gold->setCoords(currCoords);
					goldVec.emplace_back(gold);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'G'; // Must be displayed as P
				}
				else if (curr == '9') {
					auto gold = factory.createGold("dh");
					gold->setCoords(currCoords);
					goldVec.emplace_back(gold);
					defaultGrid[i][j] = '.';
					theBoard[i][j] = 'G'; // Must be displayed as P
				}
			}
		}
		for(int i = 0; i < goldVec.size(); ++i) {
			if (goldVec[i]->goldType() == 'd') {
				auto dragonHoardCoords = goldVec[i]->getCoords();
				auto dragonCoords = scanDragon(dragonHoardCoords);
				auto dragon = findEnemy(dragonCoords);
				shared_ptr<ConcreteDragon> dragonCast = static_pointer_cast<ConcreteDragon>(dragon);
				shared_ptr<ConcreteDragonHoard> castDragonHoard = static_pointer_cast <ConcreteDragonHoard>(goldVec[i]);
				castDragonHoard->attach(dragonCast);
				dragonCast->attachHoard(castDragonHoard);
			}
		}
		makeChamber();
		view->setBoard(theBoard);
		view->addMessage("Player character has been spawned.");
		if(!(filePresent)) { // Must have random generation.
			spawnPlayer();
		}
	} catch(ios::failure&) {
		view->addMessage("File not present, you must try again.");
	}
}

Floor::~Floor() {}


pair<int, int> Floor::scanDragon(pair<int, int> coords) {
	int xcoord = get<0>(coords);
	int ycoord = get<1>(coords);
	pair <int, int> dragonCoords {-1, -1};
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if (theBoard[xcoord + i][ycoord + j] == 'D') {
				get<0>(dragonCoords) = xcoord + i;
				get<1>(dragonCoords) = ycoord + j;
				return dragonCoords;
			}
		}
	}
	return dragonCoords;
}


void Floor::spawnPlayer() {
	int chamberNum = rand() % 5;
	pair <int, int> playerCoords = chamberVec[chamberNum]->placeElement();
	myPlayer->setCoords(playerCoords);
	theBoard [get<0>(playerCoords)] [get<1>(playerCoords)] = '@';
	view->updateAt(playerCoords, '@');
	spawnStairs(chamberNum);
}

void Floor::spawnStairs(int chamberNum) {
	int stairNum = rand() % 5;
	while(stairNum == chamberNum) {
		stairNum = rand() % 5;
	}
	pair<int, int> stairCoords = chamberVec[stairNum]->placeElement();
	theBoard [get<0>(stairCoords)] [get<1>(stairCoords)] = '\\';
	view->updateAt(stairCoords, '\\');
	spawnPotion();
}

void Floor::spawnPotion() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int potionNum = rand() % 6;
		potionVec.emplace_back(factory.createPotion(potionType[potionNum]));
		pair <int, int> potionCoords;
		do { // Ensure the cell chosen is empty
			potionCoords = chamberVec[chamberNum]->placeElement();
		}while (theBoard [get<0>(potionCoords)] [get<1>(potionCoords)] != '.');

		potionVec.back()->setCoords(potionCoords);
		theBoard [get<0>(potionCoords)] [get<1>(potionCoords)] = 'P';
		view->updateAt(potionCoords, 'P');
	}
	spawnGold();
}

void Floor::spawnGold() {
	for(int i = 0; i < numItems; ++i) {
		int chamberNum = rand() % 5;
		int goldNum = rand() % 8;
		goldVec.emplace_back(factory.createGold(goldType[goldNum]));
		pair <int, int> goldCoords;
		do { // Ensure the cell chosen is empty
			goldCoords = chamberVec[chamberNum]->placeElement();
		}while (theBoard [get<0>(goldCoords)] [get<1>(goldCoords)] != '.');

		goldVec.back()->setCoords(goldCoords);
		theBoard [get<0>(goldCoords)] [get<1>(goldCoords)] = 'G';
		view->updateAt(goldCoords, 'G');
		if (goldNum == 1) { // We created a dragon gold type, so we must spawn the dragon in this case!
			enemyVec.emplace_back(factory.createEnemy("d"));
			shared_ptr<ConcreteDragonHoard> castDragonHoard = static_pointer_cast <ConcreteDragonHoard>(goldVec.back());
			shared_ptr<ConcreteDragon> dragonCast = static_pointer_cast<ConcreteDragon>(enemyVec.back());
			castDragonHoard->attach(dragonCast); // attach the dragon to the hoard. 
			pair<int, int> dragonCoords;
			do {
				dragonCoords = chamberVec[chamberNum]->placeDragon(goldCoords);
			} while( theBoard[get<0>(dragonCoords)] [get<1>(dragonCoords)] != '.');
			theBoard[get<0>(dragonCoords)] [get<1>(dragonCoords)] = 'D';
			view->updateAt(dragonCoords, 'D');
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
		pair <int, int> enemyCoords;
		do {
			enemyCoords = chamberVec[chamberNum]->placeElement();
		}while (theBoard [get<0>(enemyCoords)] [get<1>(enemyCoords)] != '.');

		enemyVec.back()->setCoords(enemyCoords);
		theBoard [get<0>(enemyCoords)] [get<1>(enemyCoords)] = enemyVec.back()->displayDisplaySymbol();
		view->updateAt(enemyCoords, theBoard[get<0>(enemyCoords)][get<1>(enemyCoords)]);
	}
}

void Floor::removePotion(pair <int, int> coords) {
	int length = potionVec.size();
	for(int i = 0; i < length; ++i) {
		if(potionVec[i]->getCoords() == coords) {
			potionVec[i].reset();
			potionVec.erase( potionVec.begin() + i ); // Remove the pointer from the vector as well.
			theBoard[get<0>(coords)][get<1>(coords)] = '.'; // Board now displays a '.' where earlier there was a potion.
			view->updateAt(coords, '.');
			break;
		}
	}
}

void Floor::removeGold(pair <int, int> coords) {
	int length = goldVec.size();
	for(int i = 0; i < length; ++i) {
		if(goldVec[i]->getCoords() == coords) {
			goldVec[i].reset();
			goldVec.erase( goldVec.begin() + i ); // Remove the pointer from the vector as well.
			theBoard[get<0>(coords)][get<1>(coords)] = '.';
			view->updateAt(coords, '.');
			break;
		}
	}
}

void Floor::removeEnemy(pair <int, int> coords) {
	int length = enemyVec.size();
	for(int i = 0; i < length; ++i) {
		if(enemyVec[i]->getCoords() == coords) {
			enemyVec[i].reset();
			enemyVec.erase( enemyVec.begin() + i ); // Remove the pointer from the vector as well.
			theBoard[get<0>(coords)][get<1>(coords)] = '.';
			view->updateAt(coords, '.');
			break;
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

void Floor::movePlayer(string direction) {
	pair <int, int> checkCoords = myPlayer->checkMove(direction);
	char nextPos = theBoard[get<0>(checkCoords)] [get<1>(checkCoords)];
	pair <int, int> playerCoords = myPlayer->getCoords();
	if(nextPos == '.' || nextPos == '+' || nextPos == '#' ) {
		char defaultSymbol = defaultGrid[get<0>(playerCoords)][get<1>(playerCoords)];
		theBoard[get<0>(playerCoords)][get<1>(playerCoords)] = defaultSymbol;
		view->updateAt(playerCoords, defaultSymbol); // Update previous coords as default coords in view.
		// Replace theBoard with default symbol at the vacated position.
		theBoard[get<0>(checkCoords)] [get<1>(checkCoords)] = '@';
		view->updateAt(checkCoords, '@');
		myPlayer->setCoords(checkCoords);
	}
	else if (nextPos == 'P') {
		view->addMessage("Try picking up instead eh? gg");
	}
	else if (nextPos == 'G') {
		auto g = findGold(checkCoords);
		if (g->canPickup()) {
			g->getPickedBy(*myPlayer);
			removeGold(checkCoords);
				// Gold has been picked up, now you must move over the grid as normal.
			char defaultSymbol = defaultGrid[get<0>(playerCoords)][get<1>(playerCoords)];
			theBoard[get<0>(playerCoords)][get<1>(playerCoords)] = defaultSymbol;
				view->updateAt(playerCoords, defaultSymbol); // Update previous coords as default coords in view.
				// Replace theBoard with default symbol at the vacated position.
				theBoard[get<0>(checkCoords)] [get<1>(checkCoords)] = '@';
				view->updateAt(checkCoords, '@');
				myPlayer->setCoords(checkCoords);
			} else {
				view->addMessage("The dragon gets angrier. gg");
			}
		}
		else if (nextPos == '-' || nextPos == '|') {
			view->addMessage("Ooops watch where you're going eh? gg");
		}
		else if (nextPos == '\\') {
			if (floorNum != 5) {
				view->addMessage("On to the next floor there, eh? gg");
			}
			else {
				view->addMessage("You're the man now, eh? gg");
			// Game ends
			}
			return;
		}
	else { // Enemy case
		view->addMessage("Player tried to move on a spot occupied by an enemy. Player should try attacking instead. ");
	}
}

void Floor::scanDragonHoards() {
	int length = goldVec.size();
	for (int i = 0; i < length; ++i) {
		if (goldVec[i]->goldType() == 'd') {
			pair<int, int> scannedCoords = scanAttack(goldVec[i]->getCoords());
			bool dragonHostile = false;
			if (get<0>(scannedCoords) != -1 && get<1>(scannedCoords) != -1) {
				dragonHostile = true; // Player is in the vicinity. Dragon should be hostile. 
			}
			shared_ptr<ConcreteDragonHoard> castDragonHoard = static_pointer_cast <ConcreteDragonHoard>(goldVec[i]);
			castDragonHoard->notifyObservers(dragonHostile);
		}
	}
}

pair<int, int> Floor::scanAttack(pair<int, int> coords) {
	int xcoord = get<0>(coords);
	int ycoord = get<1>(coords);
	pair <int, int> playerCoords {-1, -1};
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if (theBoard[xcoord + i][ycoord + j] == '@') {
				get<0>(playerCoords) = xcoord + i;
				get<1>(playerCoords) = ycoord + j;
				return playerCoords;
			}
		}
	}
	return playerCoords;
}

void Floor::possibleMoves(pair<int, int> coords, vector<pair<int, int>> &possible) { // Fills up the vector
	int xcoord = get<0>(coords);
	int ycoord = get<1>(coords);
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if (theBoard[xcoord + i][ycoord + j] == '.' && !(i == 0 && j == 0)) {
				pair <int, int> moveCoords;
				get<0>(moveCoords) = xcoord + i;
				get<1>(moveCoords) = ycoord + j;
				possible.emplace_back(moveCoords);
			}
		}
	}
}

void Floor::moveEnemies() {
	scanDragonHoards(); // To reflect player movements in hostility of dragons.
	for(int i = 0; i < numRows; ++i) {
		for(int j = 0; j < numCols; ++j) {
			for(int k = 0; k < 7; ++k) {
				if (theBoard[i][j] == allEnemies[k]) {
					pair<int, int> enemyCoords{i, j};
					auto foundEnemy = findEnemy(enemyCoords);
					if (foundEnemy->hasMoved()) {
						break; // Enemy has already moved on this turn.
					} else {
						foundEnemy->setMoved(true);
						// To avoid more than one moves, the enemy has not mvoed this turn.
						// Allow it to move, and set it's moved to reflect that.
					}
					if (foundEnemy->isHostile()) {
						pair<int, int> scannedCoords = scanAttack(enemyCoords);
						if (get<0>(scannedCoords) != -1 && get<1>(scannedCoords) != -1) {
							int hitMiss = rand() % 2;
							string enemyName = foundEnemy->getEnemyName();
							if (hitMiss) {
								int before = myPlayer->getHP();
								foundEnemy->attack(*myPlayer);
								ostringstream ss; 
								int damage = before - myPlayer->getHP();
								ss << damage;
								string damageDealt = ss.str();
								view->addMessage(" The ");
								view->addMessage(enemyName);
								view->addMessage(" attacked the player. It resulted in HP loss of ");
								view->addMessage(damageDealt);
								view->addMessage("");
							} else {
								view->addMessage("The ");
								view->addMessage(enemyName);
								view->addMessage(" tried to attack the player, but he missed.");
							}
							if (myPlayer->getHP() == 0) {
								view->addMessage(" The player's HP has reached 0, you lost the game."); // Restart etc has to be done.
								return;
								// Game over.
							}
							break; // Because then you do not want the enemy to move.
						}
					}
					// Move the player now. 
					vector<pair <int, int>> possible; 
					possibleMoves(enemyCoords, possible); 
					int length = possible.size();
					int move = rand() % length;
					if(theBoard[i][j] != 'D') {
						foundEnemy->setCoords(possible[move]); // Move the enemy to new co-ordinates, randomly generated. 
						theBoard[i][j] = defaultGrid[i][j]; // The vacated co-ordinates
						view->updateAt(pair<int, int> {i, j}, defaultGrid[i][j]);
						theBoard[get<0>(possible[move])] [get<1>(possible[move])] = foundEnemy->displayDisplaySymbol();
						view->updateAt(possible[move], foundEnemy->displayDisplaySymbol());
						break;
					}
				}
			}
		}

	}
	// Reset the move in every enemy. 
	for(int i = 0; i < enemyVec.size(); ++i) {
		enemyVec[i]->setMoved(false);
	}
}


void Floor::pickPotion(string direction) {
	pair<int, int> tentativePotion = myPlayer->checkMove(direction);
	auto foundPotion = findPotion(tentativePotion);
	if (foundPotion) {
		foundPotion->getPickedBy(*myPlayer);
		removePotion(tentativePotion); 
		string itemName = foundPotion->getItemName();
		view->addMessage("Player used a potion of type ");
		view->addMessage(itemName);
		view->addMessage(".");
	} else {
		view->addMessage("The direction chosen did not contain a potion, no effect on player.");
	}
}

void Floor::playerAttack(string direction) {
	pair<int, int> enemyCoords = myPlayer->checkMove(direction);
	auto foundEnemy = findEnemy(enemyCoords);
	if (foundEnemy) {
		int before = foundEnemy->getHP();
		myPlayer->attack(*foundEnemy);
		string enemyName = foundEnemy->getEnemyName();
		int damage = before - foundEnemy->getHP();
		ostringstream ss;
		ss << damage;
		string damageDealt = ss.str();
		view->addMessage("Player attacked the ");
		view->addMessage(enemyName);
		view->addMessage(". Amount of damage dealt was: ");
		view->addMessage(damageDealt);
		view->addMessage(".");
		if (foundEnemy->getHP() == 0) {
			foundEnemy->whenDead(*myPlayer);
			removeEnemy(enemyCoords);
			view->addMessage(" Player managed to kill the ");
			view->addMessage(enemyName);
			view->addMessage(".");
		}
	} else {
		view->addMessage("Player tried to attack thin air, it was not very effective.");
	}
}