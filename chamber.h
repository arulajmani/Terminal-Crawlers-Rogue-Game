#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "floor.h"
#include <pair>
#include <vector>

class Chamber: public Floor {
	std::vector<std::pair<int, int>> chamberCoords;
public:
	Chamber();
	~Chamber();

	void placeElement(GameElement *element);

};

#endif
