#ifndef _GAMEELEMENT_H_
#define _GAMEELEMENT_H_
#include <utility> 

class GameElement {
	std::pair<int, int> coords;
	int xcoord; 
	int ycoord;

public:
	GameElement();
	~GameElement()=0;

	std::pair<int, int> getCoords();

	void setCoords(std::pair<int, int> newCoords);
};

#endif