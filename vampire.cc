#include "vampire.h"

using namespace std;
const int hp = 50;
const int atk = 25;
const int def = 25;

Vampire::Vampire():Enemy(hp, atk, def, 'V'){}

Vampire::~Vampire(){}

void Vampire::whenDead(Player &p){
	p.pickItem(nh);
}

void Vampire::attack(Character &c){

}

void Vampire::getAttackedBy(Character &c){

}