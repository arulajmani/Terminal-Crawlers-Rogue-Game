#include "publisherdragonhoard.h"
#include "subscriberdragon.h"

const int goldValue = 8;

PublisherDragonHoard::PublisherDragonHoard():Gold(goldValue), dragon{nullptr}{}

PublisherDragonHoard::~PublisherDragonHoard(){}

void PublisherDragonHoard::attach(SubscriberDragon* subDragon){
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

