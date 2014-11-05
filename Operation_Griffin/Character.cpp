#include "Character.h"
#include <iostream>
#include <iomanip>

/**/
void Character::setWeapon(Weapon* pWeapon)
{
	if (pWeapon != NULL)
		weapon = pWeapon;
	else
		;//Throw error?
}



/**/
void Character::draw()
{
	std::cout << me << std::setw(3);
}