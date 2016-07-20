#include "gold.h"
using namespace std;

Gold::Gold(int value): value{value} {}

int Gold::getValue() { return value; }

virtual bool Gold::canPickup() { return true; }

virtual char Gold::goldType() { return 'o'; }
