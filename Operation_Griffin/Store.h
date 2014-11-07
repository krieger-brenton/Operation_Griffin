#ifndef STORE_H
#define STORE_H

#include "mtrand.h"
#include "Item.h"
#include "time.h"

#define STORE_SIZE 10


/**********************************************
* Class Store
* Generates and shows items.
**********************************************/
class Store
{
public:
	Store() {rand.seed(time(0)); }
	void generateItems();
	void showItems();
private:
	MTRand_int32 rand;
	Item* store[STORE_SIZE];
};

#endif /* STORE_H */