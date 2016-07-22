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
	int hp = myPlayer->getHP();
	int atk = myPlayer->getAtk();
	int def = myPlayer->getDef();
	int goldAmt = myPlayer->getGold();
	string race = myPlayer->getRace();
	cout << "Race: "<< race<< " Gold: "<< goldAmt<<endl;
	cout<< "HP: "<<hp;
	cout<<"Attack: "<<atk;
	cout<<"Defence: "<<def;
	string message = displayMessage.str();
	cout<<message;
	displayMessage.str(""); // From stackovderfow, to reset the string stream. Must check.
}