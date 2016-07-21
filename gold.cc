#include "gold.h"
using namespace std;

Gold::Gold(int value): value{value} {}

int Gold::getValue() { return value; }

bool Gold::canPickup() { return true; }

char Gold::goldType() { return 'o'; }
