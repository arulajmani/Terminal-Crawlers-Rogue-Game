#ifndef _GAMEELEMENT_H_
#define _GAMEELEMENT_H_
#include <utility> 
#include <memory>

class GameElement {
	std::pair<int, int> coords;

public:
	GameElement();
	virtual ~GameElement()=0;

	std::pair<int, int> getCoords();

	void setCoords(std::pair<int, int> newCoords);
};

#endif

