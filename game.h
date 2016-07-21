#ifndef _GAME_H_
#define _GAME_H_
#include <race>
#include "floor.h"
#include "factory.h"

class Game {
	Floor *floor;
	std::shared_ptr <Player>myPlayer;
	int floorNum;

public:
	Game();
	~Game();

	void init(bool filePresent, char *floorPlan);
	void createPlayer(std::string race);
	void play();
	void display();

};

#endif