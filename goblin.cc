#include "goblin.h"

using namespace std;

const int hp = 70;
const int atk = 5;
const int def = 10;

Goblin::Goblin(): Enemy(hp, atk, def, 'G'){}

Goblin::~Goblin(){}

void Goblin::whenDead(Player &p){
	p.pickItem(nh); 
}

void Goblin::attack(Character &c){

}

void Goblin::getAttackedBy(Character &c){

}