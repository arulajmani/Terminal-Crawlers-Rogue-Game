#include "view.h"
#include <iostream>

using namespace std;

View::View() {}
View::~View() {}

void View::updateAt(std::pair<int, int> coords, char updateTo) {
	displayBoard[get<0>(coords)][get<1>(coords)] = updateTo;
}


void View::setBoard(char theBoard[numRows][numCols]) {
	for(int i = 0; i < numRows; ++i) {
		for(int j = 0; j < numCols; ++j) {
			displayBoard[i][j] = theBoard[i][j];
		}
	}
}


void View::addMessage(std::string message) {
	displayMessage << message;
}

void View::display() {
	for(int i = 0; i < numRows; ++i) {
		for(int j = 0; j < numCols; ++j) {
			cout<<displayBoard[i][j];
		}
		cout<<endl;
	}
	string message = displayMessage.str();
	cout<<message;
	displayMessage.str(""); // From stackoverfow, to reset the string stream. Must check.
}