#include "Character.h"
#include "Armor.h"
#include <iostream>
#include <iomanip>

/**/
void Character::setDirection(int pDirection)
{
	if (pDirection >= NORTH && pDirection <= WEST)
		direction = pDirection;
	else
		std::cerr << "ERROR is set Direction" << std::endl;
}

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

/**/
void Character::setArmor(Armor* pArmor)
{
	if (pArmor != NULL)
		armor[pArmor->getType()] = pArmor;
	else
		; //throw error?
}