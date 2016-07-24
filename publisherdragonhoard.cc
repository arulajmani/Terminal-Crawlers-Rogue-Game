#include "publisherdragonhoard.h"
#include "subscriberdragon.h"
using namespace std;


const int goldValue = 8;

PublisherDragonHoard::PublisherDragonHoard():Gold(goldValue, "Dragon Hoard"), dragon{nullptr}, dragonPresent{true}{}

PublisherDragonHoard::~PublisherDragonHoard(){}

void PublisherDragonHoard::attach(shared_ptr <SubscriberDragon> subDragon){
	dragon = subDragon;
}


bool PublisherDragonHoard::canPickup(){
	return not dragonPresent;
}

void PublisherDragonHoard::notifyObservers(bool dragonHostile){
	dragon->notify(dragonHostile);
}

void PublisherDragonHoard::dragonSlayed() {
	dragonPresent = false;
}
