#include "vampire.h"

using namespace std;
const int hpVal = 50;
const int atkVal = 25;
const int defVal = 25;

Vampire::Vampire():Enemy(hpVal, atkVal, defVal, 'V', "Vampire"){}

Vampire::~Vampire(){}

void Vampire::whenDead(Player &p){
	p.pickItem(nh);
}

