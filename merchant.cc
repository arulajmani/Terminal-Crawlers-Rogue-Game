#include "merchant.h"

using namespace std;
const int hp = 30;
const int atk = 70;
const int def = 5;

Merchant::hostile = false;

Merchant::Merchant(): Enemy(hp, atk, def, 'M'){}

Merchant::~Merchant(){}

void Merchant::makeHostile(){
	hostile = true;
}

bool Merchant::isHostile(){
	return hostile;
}

void Merchant::whenDead(Player &p){
	p.pickItem(merchantHoard); //this should add the value of nh to p's gold
}

void Merchant::attack(Character &c){

}

void Merchant::getAttackedBy(Character &c){

}