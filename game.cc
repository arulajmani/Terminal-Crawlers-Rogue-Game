#include "game.h"
#include "view.h"
#include <iostream> 


using namespace std;

Game::Game(string floorPlan, bool filePresent): floorPlan{floorPlan} , filePresent{filePresent}, floorNum{1}, myPlayer{nullptr}, floor{nullptr}, won{false}, view{nullptr} {
	//view = make_shared<View>(myPlayer);
} 

Game::~Game() {}

void Game::display() {
	view->display();
}

void Game::init() {
	floor = make_shared<Floor>(floorNum, myPlayer, filePresent, floorPlan, view);
}

void Game::createPlayer(std::string race) {
	myPlayer = factory.createPlayer(race);
	view = make_shared<View>(myPlayer, floorNum);
}

void Game::movePlayer(string direction) {
	bool crossed = floor->movePlayer(direction);
	if (floorNum == 5 and not crossed) {
		won = true;
		return;
	}
	else if (crossed) {
		myPlayer->reset();
		init();
	}
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

bool Game::isWon() {
	return won;
}