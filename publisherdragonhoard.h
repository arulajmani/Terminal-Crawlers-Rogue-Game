#ifndef _PUBLDRAGHO_H_
#define _PUBLDRAGHO_H_
#include "gold.h"

class SubscriberDragon;

class PublisherDragonHoard : public Gold  {
	const value = 8;
	SubscriberDragon *dragon; // There always has to be one dragon, so not a vector
public: 
	PublisherDragonHoard();
	virtual ~PublisherDragonHoard()=0;

	void attach(SubscriberDragon *subDragon);
	void notifyObservers();
	void detatchObservers(); // Once the dragon is destroyed, must detach to make the pointer null.
	bool canPickup(); // Check if the dragon pointer is null, only then can be picked up
};

#endif