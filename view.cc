#include "view.h"
#include <iostream>
#include <memory>
// Figure out the displayin of the floor num, probably store it as a variable in view itself. 
using namespace std;

View::View(shared_ptr <Player> myPlayer, int &floorNum): myPlayer{myPlayer} , floorNum{floorNum} {}
View::~View() {}

void View::updateAt(std::pair<int, int> coords, char updateTo) {
	displayBoard[get<0>(coords)][get<1>(coords)] = updateTo;
}


void View::setBoard(char theBoard[numberRows][numberCols]) {
	for(int i = 0; i < numberRows; ++i) {
		for(int j = 0; j < numberCols; ++j) {
			displayBoard[i][j] = theBoard[i][j];
		}
	}
}


void View::addMessage(std::string message) {
	displayMessage << message;
}

void View::display() {
	for(int i = 0; i < numberRows; ++i) {
		for(int j = 0; j < numberCols; ++j) {
			cout<<displayBoard[i][j];
		}
		cout<<endl;
	}
	int hp = myPlayer->getHP();
	int atk = myPlayer->getAtk() + myPlayer->getLevelAtk();
	int def = myPlayer->getDef() + myPlayer->getLevelDef();
	double goldAmt = myPlayer->printGold();
	string race = myPlayer->getRace();
	int floorNumber = min(5, floorNum);
	cout << "Race: "<< race<< "        Gold: "<< goldAmt<< "                                      Floor Number: " << floorNumber <<endl;
	cout<< "HP: "<<hp<<endl;
	cout<<"Attack: "<<atk<<endl;
	cout<<"Defence: "<<def<<endl;
	string message = displayMessage.str();
	cout<<"Action: "<<message<<endl;
	displayMessage.str(""); // From stackoverflow, to reset the string stream. Must check.
}

