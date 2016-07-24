#include "game.h"
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>

vector<string> directions{"no", "so", "ea", "we","ne", "se", "nw", "sw"};

void greeting() {
	cout << "Welcome to Chamber Crawler 3000. Choose your race from any of: h, e, o, d."<<endl;
	cout <<"h(human) -> HP(140) : Attack(20) : Defence(20)"<<endl;
	cout << "e(lf) -> HP(140) : Attack(30) : Defence(10) : Special Ability (negative potions have positive effects)"<<endl;
	cout << "o(rc) -> HP(180) : Attack(30) : Defence(25) : Special Ability (Gold counts for half its value)"<<endl;
	cout << "d(warf) -> HP(100) : Attack(20) : Defence(30) : Special Ability (Gold counts for 2X its value)"<<endl;
	cout <<"q -> Quit"<<endl;
}

void instructions() {
	cout << "Here is how the game is played"<<endl;
	cout <<"<direction> {no, so, ea, we, ne, ew, se, sw} move the player in the specified directions."<<endl;
	cout << "u <direction> : uses the potion indicated by the direction."<<endl;
	cout << "a <direction> : attacks the enemy in the specified direction, if it is in a one block radius."<<endl;
	cout << "r : restarts the game" <<endl;
	cout << "q : timid player admits defeat and quits the game"<<endl;

}

string chooseRace() {
	string input;
	cin.exceptions(ios::failbit|ios::eofbit);
	while(true) {
		try {
			cin >> input;
			if (input == "h" || input == "d" || input == "o" || input == "e" || input == "q") {
				break;
			} else {
				cout <<"Please enter valid input"<<endl;
			}

		} catch(ios::failure&) {
			cout<<"Choose a player race, or quit the game."<<endl;
		}	
	}
	return input;
}

shared_ptr<Game> restartGame(shared_ptr<Game> game, bool filePresent, string floorPlan) {
	game = make_shared<Game>(floorPlan, filePresent);
	string input = chooseRace();
	if (input == "q") {
		return nullptr;
	}
	game->createPlayer(input);
	game->init();
	cout << "Here is your new starting board"<<endl;
	game->display();
	return game;
}


int main(int argc, char *argv[]) {
	srand(time(NULL)); // Seeding the rand for the whole game.
	bool filePresent = true; // Change this to false at teh end.
	string floorPlan = "provided_1.txt";
	if (argc >= 2) { // File was supplied.
		filePresent = true;
		floorPlan = argv[1];
	}
	greeting();
	string input = chooseRace();
	if (input == "q") {
		return 0;
	}
	shared_ptr<Game> game = make_shared<Game>(floorPlan, filePresent);
	game->createPlayer(input);
	game->init();
	instructions();
	cout << "Here is the starting board"<<endl;
	game->display();
	cin.exceptions(ios::failbit|ios::eofbit);
	// Set up, now allow player interaction and him to make moves.
	while(true) {
		if (game->isDead()) {
			cout << "You lost the game, the player is dead. Would you like to play again? (y/n)"<<endl;
			string decision;
			try {
				cin >> decision;
			} catch (ios::failure&) {
				cout << "Please enter a valid command"<<endl;
			}
			if (decision == "y") {
				game = restartGame(game, filePresent, floorPlan);
				if (game == nullptr) {
					return 0;
				}
			} else {
				cout << "Thanks for playing CC3K"<< endl;
				return 0;
			}
		}
		string playerMove;
		try {
			cin >> playerMove;
		} catch(ios::failure&) {
			cout << "Please enter a valid command."<<endl;
		}
		if (find(directions.begin(), directions.end(), playerMove) != directions.end()) {
			game->movePlayer(playerMove);
		}
		else if (playerMove == "u") {
			string direction;
			try {
				cin >> direction;
			} catch(ios::failure&) {
				cout << " Please enter a valid command. "<<endl;
			}
			if (find(directions.begin(), directions.end(), direction) != directions.end()){
				game->usePotion(direction);
			} else {
				cout << "The direction you entered was not valid. "<<endl;
			}
		}
		else if(playerMove == "a") {
			string direction;
			try {
				cin >> direction;
			} catch(ios::failure&) {
				cout << " Please enter a valid command. "<<endl;
			}
			if (find(directions.begin(), directions.end(), direction) != directions.end()){
				game->attackEnemy(direction);
			} else {
				cout << "The direction you entered was not valid. "<<endl;
			}
		}
		else if(playerMove == "r") {
			game = restartGame(game, filePresent, floorPlan);
			if (game == nullptr) {return 0;}
		}
		else if (playerMove == "q") {
			cout <<"Thanks for playing CC3K."<<endl;
			return 0;
		} else {
			cout <<"Please enter a valid command"<<endl;
		}
		game->display();
	}
}