#include "Character.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include "GameData.h"


/**/
Character::Character() {
	me = PLAYER;
	Strength = 1; 
	Health = 2; 
	Agility = 1; 
	Intelligence = 1; 
	weapon = new Weapon();
	for (auto a : armor)
		a = new Armor();
	fAlive = true;
}
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

void Character::update()
{
	int health = getHealth();
	if (health <= 0)
	{
		kill();
		GameData::instance()->map.draw();
		GameData::instance()->message += "\n";
		GameData::instance()->message += me;
		GameData::instance()->message += " dies an ignominious death.";
	}
}
