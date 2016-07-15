#include "werewolf.h"

using namespace std;

Werewolf::Werewolf(): Enemy(120, 30, 5){}

Werewolf::~Werewolf(){}


void Werewolf::whenDead(Player &p){
	p.pickItem(nh);
}

void Werewolf::attack(Character &c){

}

void Werewolf::getAttackedBy(Character &c){

}