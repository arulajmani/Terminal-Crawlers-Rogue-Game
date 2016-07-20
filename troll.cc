#include "troll.h"

using namespace std;
const int hp = 120;
const int atk = 25;
const int def = 15;

Troll::Troll(): Enemy(hp, atk, def,'T'){}

Troll::~Troll(){}

void Troll::whenDead(Player &p){
	p.pickItem(nh);
}

void Troll::attack(Character &c){

}

void Troll::getAttackedBy(Character &c){

}