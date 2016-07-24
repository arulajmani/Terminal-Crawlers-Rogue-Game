#include "concretedragon.h"
#include "concretedragonhoard.h"
#include <iostream>
using namespace std;

const int hpVal = 15;
const int atkVal = 20;
const int defVal = 20;

ConcreteDragon::ConcreteDragon(): SubscriberDragon(hpVal, atkVal, defVal), hostile{false}, dragonHoard{nullptr}{}

ConcreteDragon::~ConcreteDragon() {
	cout << "Dtor called"<<endl;
}

void ConcreteDragon::notify(bool dragonHostile){
	hostile = dragonHostile;
}

bool ConcreteDragon::isHostile(){
	return hostile;
}

void ConcreteDragon::whenDead(Player &p){ 
	dragonHoard->dragonSlayed();
}

void ConcreteDragon::attachHoard(shared_ptr<ConcreteDragonHoard> concDragonHoard) {
	dragonHoard = concDragonHoard;
}
