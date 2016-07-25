#include "troll.h"

using namespace std;
const int hpVal = 120; 
const int atkVal = 25;
const int defVal = 15;

Troll::Troll(): Enemy(hpVal, atkVal, defVal,'T', "Troll"){}

Troll::~Troll(){}

void Troll::whenDead(Player &p){
	p.pickItem(nh);
}

