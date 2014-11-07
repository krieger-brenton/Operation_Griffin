#include "Armor.h"
#include <iostream>

/**/
Armor::Armor(int pType, int pMaterial, int pResistance) 
	: Item(), type(NO_TYPE), material(NO_MAT), resistance(0)
{
	setType(pType);
	setMaterial(pMaterial);
	setResistance(pResistance);
}

/**/
Armor::Armor(int pType, int pMaterial, int pResistance, int pStrength,
	int pIntelligence, int pAgility) : Item(pStrength, pIntelligence, pAgility)
{
	setName("ARMOR");
	setType(pType);
	setMaterial(pMaterial);
	setResistance(pResistance);
}

/**/
void Armor::setType(int pType)
{
	if (pType >= HEAD && pType <= NO_TYPE)
	{
		type = pType;
	}
	else
		; // throw error?
}

/**/
void Armor::setMaterial(int pMaterial)
{
	if (pMaterial >= CLOTH && pMaterial <= NO_MAT)
	{
		material = pMaterial;
	}
	else
		; // throw error?

}

/**/
void Armor::setResistance(int pResistance)
{
	if (pResistance >= 0)
	{
		resistance = pResistance;
	}
	else
		; // Throw error?
}

void Armor::print()
{
	std::string materials[5] = { "", "Cloth", "Leather", "Metal" "No Material" };
	std::string types[5] = { "", "Head", "Chest", "Legs", "No Type" };
	std::cout << "Name: " << name
		<< "\nType: " << types[type]
		<< "\nMaterial: " << materials[material]
		<< "\nResistance: " << resistance
		<< "\nStrength: " << strength
		<< "\nIntellignece: " << intelligence
		<< "\nAgility: " << agility << std::endl << std::endl;
}