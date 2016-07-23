#include "game.h"
#include "view.h"
#include <iostream> 


using namespace std;

Game::Game(): floorNum{0}, myPlayer{nullptr}, floor{nullptr}, view{nullptr} {
	//view = make_shared<View>(myPlayer);
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
	view = make_shared<View>(myPlayer);
}

void Game::movePlayer(string direction) {
	floor->movePlayer(direction);
}

void Game::usePotion(string direction) {
	floor->pickPotion(direction);
}
void Game::attackEnemy(string direction) {
	floor->playerAttack(direction);
}

bool Game::isDead() {
	return !(myPlayer->getHP());
}