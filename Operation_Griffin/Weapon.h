#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
class Weapon : public Item
{
public:
	Weapon() : Item(), damage(1) {}
	int getDamage() { return damage; }
	void setDamage(int pDamage);
	void print() sealed;
private:
	int damage;
};

#endif /* WEAPON_H */