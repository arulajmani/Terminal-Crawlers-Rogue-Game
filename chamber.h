#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "floor.h"
#include <utility>
#include <vector>

class Chamber: public Floor {
	int chamberNum;
	std::vector <pair<int, int>> validCoords;

public:
	Chamber(int chamberNum, std::vector<pair<int, int>> v);
	~Chamber();

	std::pair<int, int> placeElement();
	std::pair<int,int> placeDragon(std::pair<int, int> goldCoords);

};

#endif
