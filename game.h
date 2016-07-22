#ifndef _GAME_H_
#define _GAME_H_
#include "floor.h"
#include "factory.h"
#include "view.h"
#include <string>
#include "player.h"


class Game {
	Factory factory;
	std::shared_ptr<Floor> floor;
	std::shared_ptr<Player> myPlayer;
	int floorNum;
	std::shared_ptr<View> view;

public:
	Game();
	~Game();

	void init(bool filePresent, std::string floorPlan);
	void createPlayer(std::string race);
	void play();
	void display();

	void movePlayer(std::string direction);
	// Not made
	void usePotion(std::string direction);
	void attackEnemy(std::string direction);
	bool isDead();
};

#endif