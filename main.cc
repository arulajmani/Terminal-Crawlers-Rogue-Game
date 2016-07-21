#include "game.h"
using namespace std;

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


int main(int argc, char *argv[]) {
	srand(time(null)); // Seeding the rand for the whole game.
	game = new Game{};
	bool filePresent = false; 
	char *floorPlan = "default.txt";
	if (argc >= 2) { // File was supplied.
		filePresent = true;
		floorPlan = argv[1];
	}
	greetings();
	cin.exceptions(ios::failbit|ios::eofbit);
	string input;
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
	if (input == "q") {
		return;
	}
	game->createPlayer()
	game->init(filePresent, floorPlan);
	instructions();
	cout << "Here is the starting board"<<endl;
	game->display();
}