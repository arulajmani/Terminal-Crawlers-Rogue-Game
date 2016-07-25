#ifndef _PUBLDRAGHO_H_
#define _PUBLDRAGHO_H_
#include "gold.h"
#include <memory>


class SubscriberDragon;

class PublisherDragonHoard : public Gold  {
protected:
	bool dragonPresent;
	std::shared_ptr <SubscriberDragon> dragon; // There always has to be one dragon, so not a vector
public: 
	PublisherDragonHoard();
	virtual ~PublisherDragonHoard()=0;

	void attach(std::shared_ptr <SubscriberDragon> subDragon);
	void notifyObservers(bool dragonHostile);
	void dragonSlayed();
	//-> shifted to concretedragonhoard //void detatchObservers(); // Once the dragon is destroyed, must detach to make the pointer null.
	bool canPickup(); // Check if the dragon pointer is null, only then can be picked up
};

#endif
