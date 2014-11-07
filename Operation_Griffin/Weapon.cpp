#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int pDamage, int pStrength, int pIntelligence, int pAgility)
	: Item(pStrength, pIntelligence, pAgility) 
{
	setDamage(pDamage);
	setName("WEAPON");
}

/*******************************
*
*******************************/
void Weapon::setDamage(int pDamage)
{
	if (pDamage >= 0)
		damage = pDamage;
	else
		;// Throw error?
}

/*******************************
*
*******************************/
void Weapon::print()
{
	std::cout << "Name: " << name
		<< "\nDamage: " << damage
		<< "\nStrength: " << strength
		<< "\nIntellignece: " << intelligence
		<< "\nAgility: " << agility << std::endl << std::endl;
}