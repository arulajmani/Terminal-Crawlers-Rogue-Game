#include "goblin.h"

using namespace std;

Goblin::Goblin(): Enemy(70, 5, 10, 'G'){}

Goblin::~Goblin(){}

void Goblin::whenDead(Player &p){
	p.pickItem(nh); 
}

void Goblin::attack(Character &c){

}

void Goblin::getAttackedBy(Character &c){

}