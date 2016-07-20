#include "normalhoard.h" 
using namespace std;

const int value = 1;

NormalHoard::NormalHoard(): Gold{value} {}
NormalHoard::~NormalHoard() {}

NormalHoard::getPickedBy(Player &p) {
	p.PickItem(*this);
}