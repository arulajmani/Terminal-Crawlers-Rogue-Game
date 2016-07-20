#include "smallhoard.h" 
using namespace std;

const int value = 2;

SmallHoard::SmallHoard(): Gold{value} {}
SmallHoard::~SmallHoard() {}

void SmallHoard::getPickedBy(Player &p) {
	p.PickItem(*this);
}