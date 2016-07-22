#include "gold.h"
using namespace std;

Gold::Gold(int value, string itemName): Item{itemName}, value{value} {}

int Gold::getValue() { return value; }

bool Gold::canPickup() { return true; }

char Gold::goldType() { return 'o'; }
