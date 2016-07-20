#include "merchanthoard.h" 
using namespace std;

const int value = 4;

MerchantHoard::MerchantHoard(): Gold{value} {}
MerchantHoard::~MerchantHoard() {}

MerchantHoard::getPickedBy(Player &p) {
	p.PickItem(*this);
}