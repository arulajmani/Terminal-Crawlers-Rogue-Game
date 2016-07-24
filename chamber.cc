#include "chamber.h"
#include <algorithm> 
#include <cstdlib>
#include <iostream>
using namespace std;

Chamber::Chamber(int chamberNum, vector <pair<int, int>> &v):chamberNum{chamberNum}, validCoords{v}{}

pair<int, int> Chamber::placeElement() {
	int position = rand() % validCoords.size();
	return validCoords[position];
}

pair<int,int> Chamber::placeDragon(std::pair<int, int> goldCoords) {
	int xcoord = get<0>(goldCoords);
	int ycoord = get<1>(goldCoords);
	pair <int, int> dragonCoords;
	do {
		xcoord = xcoord + (rand() % 3) - 1; // xcoord + 0/1/-1
		ycoord = ycoord + (rand() % 3) - 1; // ycoord + 0/1/-1
		pair <int, int> dragonCoords = {xcoord, ycoord};
	} while( find (validCoords.begin(), validCoords.end(), dragonCoords) == validCoords.end()); // Didn't find the coordinates in chamber, go again.
	return dragonCoords;
}

void Chamber::addCoords(std::pair<int, int> coords) {
	validCoords.emplace_back(coords);
}