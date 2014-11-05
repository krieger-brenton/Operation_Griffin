#include "Weapon.h"
#include <iostream>

/*******************************
*
*******************************/
void Weapon::setDamage(int pDamage)
{
	if (pDamage > 0)
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
		<< "\nAgility: " << agility << '\n';
}