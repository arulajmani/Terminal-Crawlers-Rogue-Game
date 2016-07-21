#include "view.h"

using namespace std;

View::View() {}
View::~View() {}

void View::updateAt(std::pair<int, int> coords, char updateTo) {
	displayBoard[get<0>(coords)][get<1>coords] = updateTo;
}
	void View::setBoard(char theBoard[numRows][numCols]) {
		for(int i = 0; i < numRows; ++i) {
			for(int j = 0; j < numCols; ++j) {
				displayBoard[i][j] = theBoard[i][j];
			}
		}
	}
	void addMessage(std::string message) {
		dispalyMessage << message;
	}
