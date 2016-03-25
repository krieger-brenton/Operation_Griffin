#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
class Weapon : public Item
{
public:
	Weapon() : Item(), damage(1) { setName("WEAPON"); stat = 'S'; damage = 1; }
	Weapon(int pDamage, int pStrength, int pIntelligence, int pAgility);
	int getDamage() { return damage; }
	char getStat() { return stat;  }
	void setDamage(int pDamage);
	void print(); //sealed;
	
private:
	int damage;
	char stat;
};

#endif /* WEAPON_H */
