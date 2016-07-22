#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "floor.h"
#include <utility>
#include <vector>

class Chamber{
	int chamberNum;
	std::vector <std::pair<int, int>> validCoords;

public:
	Chamber(int chamberNum, std::vector<std::pair<int, int>> v);
	
	void addCoords(std::pair<int, int> coords);
	std::pair<int, int> placeElement();
	std::pair<int,int> placeDragon(std::pair<int, int> goldCoords);

};

#endif
