#include "normalhoard.h" 
using namespace std;

const int goldValue  = 1;

NormalHoard::NormalHoard(): Gold{goldValue } {}
NormalHoard::~NormalHoard() {}

void NormalHoard::getPickedBy(Player &p) {
	p.pickItem(*this);
}