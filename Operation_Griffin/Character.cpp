#include "Character.h"
#include <iostream>

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
	std::cout << me;
}