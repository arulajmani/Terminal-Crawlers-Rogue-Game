#include "item.h"

using namespace std;

Item::Item(string name): itemName{name}{};
Item::~Item(){};

string Item::getItemName() {
	return itemName;
}

