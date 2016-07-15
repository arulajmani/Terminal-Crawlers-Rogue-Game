#include "phoenix.h"

using namespace std;

Phoenix::Phoenix(): Enemy(50, 35, 20){}

Phoenix::~Phoenix(){}

void Phoenix::whenDead(Player &p){
	p.pickItem(nh); //this should add the value of nh to p's gold
}

void Phoenix::attack(Character &c){

}

void Phoenix::getAttackedBy(Character &c){

}