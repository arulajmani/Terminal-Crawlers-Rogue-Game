#include publisherdragonhoard.h
#include subscriberdragon.h

PublisherDragonHoard::PublisherDragonHoard():Gold(value), dragon{nullptr}{}

PublisherDragonHoard::~PublisherDragonHoard(){}

void PublisherDragonHoard::attach(SubscriberDragon* subDragon){
	dragon = subDragon;
}

void PublisherDragonHoard::detatchObservers(){
	dragon = nullptr;
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

