#include "game.h"

Game::Game(int level): floorNum{0} myPlayer{nullptr} {
	view = make_shared<View>();
} 
Game::~Game() {}

void Game::Display() {
	view->display();
}

void Game::init(bool filePresent,char *floorPlan) {
	floorNum += 1;
	if (floorNum == 6) {
		// Print victory stuff. 
	}
	floor = new Floor{floorNum, myPlayer, filePresent, floorPlan, view};
}

void Game::createPlayer(std::string race) {
	myPlayer = factory.createPlayer(race);
}