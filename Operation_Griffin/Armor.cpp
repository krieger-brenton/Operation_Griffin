#include "Armor.h"
#include <iostream>

/**/
Armor::Armor(int pType, int pMaterial, int pResistance) : Item(), type(NO_TYPE), material(NO_MAT), resistance(0)
{
	setType(pType);
	setMaterial(pMaterial);
	setResistance(pResistance);
}

/**/
void Armor::setType(int pType)
{
	if (pType > HEAD && pType < NO_TYPE)
	{
		type = pType;
	}
	else
		; // throw error?
}

/**/
void Armor::setMaterial(int pMaterial)
{
	if (pMaterial > CLOTH && pMaterial < NO_MAT)
	{
		material = pMaterial;
	}
	else
		; // throw error?

}

/**/
void Armor::setResistance(int pResistance)
{
	if (pResistance > 0)
	{
		resistance = pResistance;
	}
	else
		; // Throw error?
}

void Armor::print()
{
	std::cout << "Name: " << name
		<< "\nType: " << type
		<< "\nMaterial: " << material
		<< "\nResistance: " << resistance
		<< "\nStrength: " << strength
		<< "\nIntellignece: " << intelligence
		<< "\nAgility: " << agility << '\n';
}