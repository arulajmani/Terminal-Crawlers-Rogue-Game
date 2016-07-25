#include "normalhoard.h" 
using namespace std;

const int goldValue  = 1;

NormalHoard::NormalHoard(): Gold{goldValue, "Normal Hoard"} {}
NormalHoard::~NormalHoard() {}

void NormalHoard::getPickedBy(Player &p) {
	p.pickItem(*this);
}

