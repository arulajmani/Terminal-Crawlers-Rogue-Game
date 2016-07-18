#include "chamber.h"
#include <algorithm> 
using namespace std;

Chamber::Chamber() {}
Chamber::~Chamber() {}

pair<int, int> Chamber::placeElement() {
	int position = rand() % chamberCoords.size();
	return chamberCoords[position];
}

pair<int,int> placeDragon(std::pair<int, int> goldCoords) {
	int xcoord = get<0>(goldCoords);
	int ycoord = get<1>(goldCoords);
	do {
		xcoord = xcoord + (rand() % 3) - 1; // xcoord + 0/1/-1
		ycoord = ycoord + (rand() % 3) - 1; // ycoord + 0/1/-1
		pair <int, int> dragonCoords = {xcoord, ycoord};
	} while( find (chamberCoords.begin(), chamberCoords.end(), dragonCoords) == chamberCoords.end()); // Didn't find the coordinates in chamber, go again.
	return dragonCoords;
}