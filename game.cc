#include "game.h"

using namespace std;

Game::Game(): floorNum{0}, myPlayer{nullptr}, floor{nullptr} {
	view = make_shared<View>();
} 

Game::~Game() {}

void Game::display() {
	view->display();
}

void Game::init(bool filePresent,string floorPlan) {
	floorNum += 1;
	if (floorNum == 6) {
		// Print victory stuff. 
	}
	floor = make_shared<Floor>(floorNum, myPlayer, filePresent, floorPlan, view);
}

void Game::createPlayer(std::string race) {
	myPlayer = factory.createPlayer(race);
}

void Game::movePlayer(std::string direction) {
	floor->movePlayer(direction);
}

void Game::usePotion(std::string direction) {
	floor->pickPotion(direction);
}
void Game::attackEnemy(std::string direction) {
	floor->playerAttack(direction);
}

bool Game::isDead() {
	return !(myPlayer->getHP());
}