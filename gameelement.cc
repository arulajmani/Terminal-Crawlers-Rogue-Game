#include "gameelement.h"

using namespace std; 

GameElement::GameElement(): coords{make_pair(-1, -1)}{}
GameElement::~GameElement() {}

pair<int, int> GameElement::getCoords() {
	return coords;
}

void GameElement::setCoords(pair<int, int> newCoords) {
	get<0>(coords) = get<0>(newCoords);
	get<1>(coords) = get<1>(newCoords);
}
