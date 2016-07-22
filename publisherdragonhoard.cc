#include "publisherdragonhoard.h"
#include "subscriberdragon.h"
using namespace std;


const int goldValue = 8;

PublisherDragonHoard::PublisherDragonHoard():Gold(goldValue, "Dragon Hoard"), dragon{nullptr}{}

PublisherDragonHoard::~PublisherDragonHoard(){}

void PublisherDragonHoard::attach(shared_ptr <SubscriberDragon> subDragon){
	dragon = subDragon;
}


bool PublisherDragonHoard::canPickup(){
	if(dragon == nullptr){
		return true;
	}
	else{
		return false;
	}
}

void PublisherDragonHoard::notifyObservers(bool dragonHostile){
	dragon->notify(dragonHostile);
}

