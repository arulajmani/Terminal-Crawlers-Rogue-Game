#include "game.h"

Game::Game(int level): floorNum{0} {} 
Game::~Game() {}

void Game::Display() {
	floor->display();
}

void Game::init(bool filePresent,char *floorPlan) {
	floorNum += 1;
	if (floorNum == 6) {
		// Print victory stuff. 
	}
	floor = new Floor{floorNum, myPlayer, floorNum, filePresent, floorPlan};
}