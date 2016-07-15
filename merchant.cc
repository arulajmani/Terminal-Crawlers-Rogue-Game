#include "merchant.h"

using namespace std;

Merchant::hostile = false;

Merchant::Merchant(): Enemy(30, 70, 5){}

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