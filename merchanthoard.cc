#include "merchanthoard.h" 
using namespace std;

const int value = 4;

MerchantHoard::MerchantHoard(): Gold{value} {}
MerchantHoard::~MerchantHoard() {}

void MerchantHoard::getPickedBy(Player &p) {
	p.PickItem(*this);
}