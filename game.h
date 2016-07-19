#ifndef _GAME_H_
#define _GAME_H_
#include <race>
#include "floor.h"
#include "factory.h"

class Game {
	Floor *floor;

public:
	Game();
	~Game();

	void init();
	void createPlayer(std::string race);
	void play();

};

#endif