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

void ConcreteDragon::notify(bool dragonHostile){
	hostile = dragonHostile;
}

bool ConcreteDragon::isHostile(){
	return hostile;
}

