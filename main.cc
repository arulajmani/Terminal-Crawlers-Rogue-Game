#include "game.h"
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
#include <memory>
#include <map>
#include <ncurses.h>

vector<string> directions{"no", "so", "ea", "we","ne", "se", "nw", "sw"};
map<int, string> wasd {{119,"no"}, {97,"we"}, {115, "so"}, {100,"ea"}};
vector<string> dlcDescription {"WASD Controls", "More characters"};
vector<bool> dlcBool {false, false};
const int WASD = 0;
const int players = 1;

void greeting() {
	cout << "Welcome to Chamber Crawler 3000. Choose your race from any of: h, e, o, d."<<endl;
	cout <<"h(uman) -> HP(140) : Attack(20) : Defence(20)"<<endl;
	cout << "e(lf) -> HP(140) : Attack(30) : Defence(10) : Special Ability (negative potions have positive effects)"<<endl;
	cout << "o(rc) -> HP(180) : Attack(30) : Defence(25) : Special Ability (Gold counts for half its value)"<<endl;
	cout << "d(warf) -> HP(100) : Attack(20) : Defence(30) : Special Ability (Gold counts for 2X its value)"<<endl;
	if (dlcBool[players]) {
		cout << "c(charizard) -> HP(160) : Attack(40) : Defence(30) : Special Ability (Performs special attack every 4th move, must recharge the next move)"<<endl;
		cout << "s(layer) -> HP(150) : Attack(25) : Defence(15) : Special Ability (Can kill one prechosen enemy in one strike)"<<endl;
	}
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
			if (input == "h" || input == "d" || input == "o" || input == "e" || input == "q" || (dlcBool[players] && (input == "c" || input == "s"))) {
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
	cout << "Please enter a new race to play the new game: "<<endl;
	string input = chooseRace();
	if (input == "q") {
		return nullptr;
	}
	game->createPlayer(input);
	if (input == "s") { // Slayer case, ask user for enemy.
		cout << "Choose the foe you would like to kill in one strike: V(ampire), N(Goblin), X(Pheonix), M(erchant), W(erewolf), T(roll), D(ragon)"<<endl;
		char enemy;
		cin >> enemy;
		game->setEnemy(enemy);
	}
	game->init();
	cout << "Here is your new starting board"<<endl;
	game->display();
	return game;
}

shared_ptr<Game> playerDead (shared_ptr<Game> game, bool filePresent, string floorPlan) {
	cout << "You lost the game, the player is dead. Would you like to play again? (y/n)"<<endl;
	string decision;
	try {
		cin >> decision;
	} catch (ios::failure&) {
		cout << "Please enter a valid command"<<endl;
	}
	if (decision == "y") {
		game = restartGame(game, filePresent, floorPlan);
	} else {
		cout << "Thanks for playing CC3K"<< endl;
		return nullptr;
	}
	return game;
}

int main(int argc, char *argv[]) {

	// DLC set up.
	for (int i = 0; i < dlcDescription.size(); ++i) {
		cout << "Would you like to turn on "<< dlcDescription[i] << "(y/n)";
		string decision;
		cin >> decision;
		if (decision == "y") {
			dlcBool[i] = true;
		}
	}


	srand(time(NULL)); // Seeding the rand for the whole game.
	bool filePresent = false; // Change this to false at teh end.
	string floorPlan = "default.txt";
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
	if (input == "s") { // Slayer case, ask user for enemy.
		cout << "Choose the foe you would like to kill in one strike: V(ampire), N(Goblin), X(Pheonix), M(erchant), W(erewolf), T(roll), D(ragon)"<<endl;
		char enemy;
		cin >> enemy;
		game->setEnemy(enemy);
	}
	game->init();
	if (not dlcBool[WASD])
	{
		instructions();
	}
	cout << "Here is the starting board"<<endl;
	game->display();
	cin.exceptions(ios::failbit|ios::eofbit);

	// To let user use WASD.
	if (dlcBool[WASD]) {
		while(true) {
			if (game->isDead()) {
				game = playerDead(game, filePresent, floorPlan);
				if (not game) {
					return 0;
				}
			}
			if (game->isWon()) {
				cout << "Thanks for playing CC3K"<<endl;
				return 0;
			}
			initscr();
			cbreak();
			noecho();
			int move = getch();
			endwin();
			if (move == 119 || move == 97 || move == 115 || move == 100) {
				game->wasd(wasd[move]);
				game->display();
			}
			else if (move == 'q') {
				return 0;
			}
			else if (move == 'r') {
				game = restartGame(game, filePresent, floorPlan);
				if (game == nullptr) {return 0;}
			}
			else {
				cout << "Please enter a valid command."<<endl;
			}
		}
	}

	// Normal play, without WASD
	while(true) {
		if (game->isDead()) {
			game = playerDead(game, filePresent, floorPlan);
			if (not game) {
				return 0;
			}
		}
		if (game->isWon()) {
			cout << "Thanks for playing CC3K"<<endl;
			return 0;
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

