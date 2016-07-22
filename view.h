#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <sstream>
#include <utility>

const int numRows = 25;
const int numCols = 79;
class View {
	char displayBoard [numRows][numCols];
	std::ostringstream displayMessage; 
public:
	View();
	~View();

	void updateAt(std::pair<int, int> coords, char updateTo);
	void setBoard(char theBoard[numRows][numCols]);
	void addMessage(std::string message);
	void display();
};

#endif