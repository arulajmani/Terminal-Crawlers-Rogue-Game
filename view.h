#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <sstream>
#include <utility>
#include "player.h"

const int numberRows = 25;
const int numberCols = 79;
class View {
	int &floorNum;
	char displayBoard [numberRows][numberCols];
	std::ostringstream displayMessage;
	std::shared_ptr<Player> myPlayer; 
public:
	View(std::shared_ptr<Player> myPlayer, int &floorNum);
	~View();

	void updateAt(std::pair<int, int> coords, char updateTo);
	void setBoard(char theBoard[numberRows][numberCols]);
	void addMessage(std::string message);
	void display();
};

#endif

