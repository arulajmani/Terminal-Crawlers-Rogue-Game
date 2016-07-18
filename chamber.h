#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "floor.h"
#include <utility>
#include <vector>

class Chamber: public Floor {
	std::vector<std::pair<int, int>> chamberCoords;
public:
	Chamber();
	~Chamber();

	std::pair<int, int> placeElement();
	std::pair<int,int> placeDragon(std::pair<int, int> goldCoords);

};

#endif
