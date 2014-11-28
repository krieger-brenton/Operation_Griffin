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
/*Checks armor and weapon and sets the damage
* damage = (Strength^2 + Intelligence^2 + Agility^2)/2 
* this will provide more damage for specilizing in one trait.
*/
void Character::damageUpdate()
{
	//get stats from base char
	int strength = Strength;
	int intelligence = Intelligence;
	int agility = Agility;

	//get stats from weapon
	strength += weapon->getStrength();
	intelligence += weapon->getIntelligence();
	agility += weapon->getAgility();

	//get stats from armor
	for (auto gear : armor)
	{
		if (gear != NULL)
		{
			strength += gear->getStrength();
			intelligence += gear->getIntelligence();
			agility += gear->getAgility();
		}
	}

	//get damage from weapon
	damage = (weapon == NULL) ? (1) : (weapon->getDamage) + (((Strength * Strength) + (Intelligence * Intelligence) + (Agility * Agility)) / 2);
}