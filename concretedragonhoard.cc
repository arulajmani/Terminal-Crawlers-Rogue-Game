#include "concretedragonhoard.h"

ConcreteDragonHoard::ConcreteDragonHoard() {}

ConcreteDragonHoard::~ConcreteDragonHoard(){}

/*bool ConcreteDragonHoard::getState(){
	// need to figure out how board is working, check .h for more documentation
}*/

void ConcreteDragonHoard::getPickedBy(Player &p) {
	p.pickItem(*this);
}

char ConcreteDragonHoard::goldType() {
	return 'd';
}

void ConcreteDragonHoard::detatchObservers(){
	dragon = nullptr;
}



