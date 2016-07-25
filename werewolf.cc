#include "werewolf.h"

using namespace std;

const int hpVal = 120;
const int atkVal = 30;
const int defVal = 5;

Werewolf::Werewolf(): Enemy(hpVal, atkVal, defVal, 'W', "Werewolf"){}

Werewolf::~Werewolf(){}


void Werewolf::whenDead(Player &p){
	p.pickItem(nh);
}

