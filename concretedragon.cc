#include "concretedragon.h"
#include "concretedragonhoard.h"

using namespace std;

const int hpVal = 150;
const int atkVal = 20;
const int defVal = 20;

ConcreteDragon::ConcreteDragon(): SubscriberDragon(hpVal, atkVal, defVal), hostile{false}, dragonHoard{nullptr}{
}

ConcreteDragon::~ConcreteDragon() {
	dragonHoard->detatchObservers();
}

void ConcreteDragon::notify(bool dragonHostile){
	hostile = dragonHostile;
}

bool ConcreteDragon::isHostile(){
	return hostile;
}

