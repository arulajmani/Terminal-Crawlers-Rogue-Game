#ifndef _GAMEELEMENT_H_
#define _GAMEELEMENT_H_

class GameElement {
	int xcoord; 
	int ycoord;

public:
	GameElement();
	~GameElement()=0;

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
};

#endif