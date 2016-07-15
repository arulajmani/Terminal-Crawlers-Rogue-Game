#include "vampire.h"

using namespace std;

Vampire::Vampire():Enemy(50, 25, 25){}

Vampire::~Vampire(){}

void Vampire::whenDead(Player &p){
	p.pickItem(nh);
}

void Vampire::attack(Character &c){

}

void Vampire::getAttackedBy(Character &c){

}