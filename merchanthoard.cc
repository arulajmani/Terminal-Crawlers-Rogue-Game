#include "merchanthoard.h" 
using namespace std;

const int goldValue  = 4;

MerchantHoard::MerchantHoard(): Gold{goldValue ,"Merchant Hoard"} {}
MerchantHoard::~MerchantHoard() {}

void MerchantHoard::getPickedBy(Player &p) {
	p.pickItem(*this);
}

