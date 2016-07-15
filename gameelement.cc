#include "gameelement.h"

using namespace std; 

GameElement::GameElement(): xcoord{-1} , ycoord{-1} {}
GameElement::~GameElement() {}

int GameElement::getX() {
	return xcoord;
}

int GameElement::getY() {
	return ycoord;
}

void GameElement::setX(int x) {
	xcoord = x;
}

void GameElement::setY(int y) {
	ycoord = y;
}

