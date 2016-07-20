#include "concretedragon.h"
#include "concretedragonhoard.h"

using namespace std;

const int hp = 150;
const int atk = 20;
const int def = 20;

ConcreteDragon::ConcreteDragon(): SubscriberDragon(hp, atk, def), hostile{false}, dragonHoard{nullptr}{
}

ConcreteDragon::~ConcreteDragon() {
	dragonHoard->detatch(this);
}

void ConcreteDragon::notify(){
	if(dragonHoard->getState()){
		hostile = true;
	}
	else{
		hostile = false;
	}
}

bool ConcreteDragon::isHostile(){
	return hostile;
}

