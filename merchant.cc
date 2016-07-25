#include "merchant.h"
#include <memory>

using namespace std;
const int hpVal = 30;
const int atkVal = 70;
const int defVal = 5;

bool Merchant::hostile = false;

Merchant::Merchant(): Enemy(hpVal, atkVal, defVal, 'M', "Merchant"){}

Merchant::~Merchant(){}

void Merchant::makeHostile(){
	hostile = true;
}

bool Merchant::isHostile(){
	return hostile;
}

void Merchant::whenDead(Player &p) {
	p.pickItem(merchantHoard);
}

