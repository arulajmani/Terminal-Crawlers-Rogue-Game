#include "phoenix.h"

using namespace std;

const int hpVal = 50;
const int atkVal = 35;
const int defVal = 20;

Phoenix::Phoenix(): Enemy(hpVal, atkVal, defVal, 'X', "Phoenix"){}

Phoenix::~Phoenix(){}

void Phoenix::whenDead(Player &p){
	p.pickItem(nh); //this should add the value of nh to p's gold
}
