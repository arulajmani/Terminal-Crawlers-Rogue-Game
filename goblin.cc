#include "goblin.h"

using namespace std;

const int hpVal = 70;
const int atkVal = 5;
const int defVal = 10;

Goblin::Goblin(): Enemy(hpVal, atkVal, defVal, 'N', "Goblin"){}

Goblin::~Goblin(){}

void Goblin::whenDead(Player &p){
	p.pickItem(nh); 
}

