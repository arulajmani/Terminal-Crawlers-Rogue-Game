#include "werewolf.h"

using namespace std;

const int hp = 120;
const int atk = 30;
const int def = 5;

Werewolf::Werewolf(): Enemy(hp, atk, def, 'W'){}

Werewolf::~Werewolf(){}


void Werewolf::whenDead(Player &p){
	p.pickItem(nh);
}

void Werewolf::attack(Character &c){

}

void Werewolf::getAttackedBy(Character &c){

}