#ifndef _GAME_H_
#define _GAME_H_
#include "floor.h"
#include "factory.h"
#include <string>
#include <memory>
#include "player.h"
#include "slayer.h"

class View;

class Game {
	Factory factory;
	std::shared_ptr<Floor> floor;
	std::shared_ptr<Player> myPlayer;
	int floorNum;
	bool filePresent;
	bool won;
	std::string floorPlan;
	std::shared_ptr<View> view;

public:
	Game(std::string floorPlan, bool filePresent);
	~Game();

	void init();
	void createPlayer(std::string race);
	void play();
	void display();

	void movePlayer(std::string direction);
	void usePotion(std::string direction);
	void attackEnemy(std::string direction);
	bool isDead();
	bool isWon();
	void wasd(std::string direction);
	void setEnemy(char newEnemy);
};

#endif

