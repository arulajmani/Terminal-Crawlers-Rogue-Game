#include "game.h"
#include "view.h"
#include <iostream> 


using namespace std;

Game::Game(string floorPlan, bool filePresent): floorPlan{floorPlan} , filePresent{filePresent}, floorNum{0}, myPlayer{nullptr}, floor{nullptr}, view{nullptr} {
	//view = make_shared<View>(myPlayer);
} 

Game::~Game() {}

void Game::display() {
	view->display();
}

void Game::init() {
	floorNum += 1;
	if (floorNum == 6) {
		// Print victory stuff. 
	}
	floor = make_shared<Floor>(floorNum, myPlayer, filePresent, floorPlan, view);
}

void Game::createPlayer(std::string race) {
	myPlayer = factory.createPlayer(race);
	view = make_shared<View>(myPlayer);
}

void Game::movePlayer(string direction) {
	floor->movePlayer(direction);
	floor->moveEnemies();
}

void Game::usePotion(string direction) {
	floor->pickPotion(direction);
	floor->moveEnemies();
}
void Game::attackEnemy(string direction) {
	floor->playerAttack(direction);
	floor->moveEnemies();
}

bool Game::isDead() {
	return !(myPlayer->getHP());
}