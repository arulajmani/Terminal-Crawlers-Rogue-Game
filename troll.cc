#include "troll.h"

using namespace std;

Troll::Troll(): Enemy(120, 25, 15){}

Troll::~Troll(){}

void Troll::whenDead(Player &p){
	p.pickItem(nh);
}

void Troll::attack(Character &c){

}

void Troll::getAttackedBy(Character &c){

}