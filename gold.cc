#include "gold.h"
using namespace std;

Gold::Gold(int value): value{value} {}

Gold::getPickedBy(Player &p) {
	p.PickItem(*this);
}

int Gold::getValue() { return value; }

virtual bool Gold::canPickup() { return true; }
