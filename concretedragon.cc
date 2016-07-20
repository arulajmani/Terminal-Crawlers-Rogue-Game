#include "concretedragon.h"
#include "concretedragonhoard.h"

using namespace std;

const int hp = 150;
const int atk = 20;
const int def = 20;

ConcreteDragon::ConcreteDragon(): SubscriberDragon(150, 20, 20), hostile{false}, dragonHoard{nullptr}{
	dragonHoard->attach(this);
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

