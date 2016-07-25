#include "smallhoard.h" 
using namespace std;

const int goldValue = 2;

SmallHoard::SmallHoard(): Gold{goldValue, "SmallHoard"} {}
SmallHoard::~SmallHoard() {}

void SmallHoard::getPickedBy(Player &p) {
	p.pickItem(*this);
}

