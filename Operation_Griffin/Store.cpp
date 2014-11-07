#include "Store.h"
#include "Armor.h"
#include "Weapon.h"

#define WAVE_NUMBER 1 // Just for testing
#define WAVE_CONSTANT 3 // Will need to changed for balancing

/**/
void Store::generateItems()
{
	int statMax = (WAVE_NUMBER * WAVE_CONSTANT);
	

	for (int i = 0; i < STORE_SIZE; ++i)
	{
		int strength = (rand() % statMax);
		int intelligence = (rand() % statMax);
		int agility = (rand() % statMax);

		if (rand() % 2) // Armor
		{
			int type = (rand() % 3);
			int mat = (rand() % 3);
			int resistance = ((rand() % statMax) * mat + 1);
			store[i] = new Armor(type, mat, resistance, strength, intelligence, agility);
		}
		else // Weapon
		{
			int damage = (rand() % statMax) + 1;
			store[i] = new Weapon(damage, strength, intelligence, agility);
		}
	}
}

/**/
void Store::showItems()
{
	for (int i = 0; i < STORE_SIZE; ++i)
	{
		if (store[i] != NULL)
			store[i]->print();
		else
			; //throw error?
	}
}