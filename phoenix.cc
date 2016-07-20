#include "phoenix.h"

using namespace std;

const int hp = 50;
const int atk = 35;
const int def = 20;

Phoenix::Phoenix(): Enemy(hp, atk, def, 'P'){}

Phoenix::~Phoenix(){}

void Phoenix::whenDead(Player &p){
	p.pickItem(nh); //this should add the value of nh to p's gold
}

void Phoenix::attack(Character &c){

}

void Phoenix::getAttackedBy(Character &c){

}