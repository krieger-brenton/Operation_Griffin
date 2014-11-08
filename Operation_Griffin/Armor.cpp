#include "Armor.h"
#include <iostream>

/******************************************************************************
*	Constructor : Armor(int, int, int)
******************************************************************************/
Armor::Armor(int pType, int pMaterial, int pResistance) 
	: Item(), type(NO_TYPE), material(NO_MAT), resistance(0)
{
	setName("ARMOR");
	setType(pType);
	setMaterial(pMaterial);
	setResistance(pResistance);
}

/******************************************************************************
*	Constructor : Armor(int, int, int, int, int, int)
******************************************************************************/
Armor::Armor(int pType, int pMaterial, int pResistance, int pStrength,
	int pIntelligence, int pAgility) : Item(pStrength, pIntelligence, pAgility)
{
	setName("ARMOR");
	setType(pType);
	setMaterial(pMaterial);
	setResistance(pResistance);
}

/******************************************************************************
*	
******************************************************************************/
void Armor::setType(int pType)
{
	if (pType >= HEAD && pType <= NO_TYPE)
	{
		type = pType;
	}
	else
	{
		type = NO_TYPE;
		std::cerr << "ERROR in setting type " << pType << std::endl; // throw error?
	}
}

/******************************************************************************
*
******************************************************************************/
void Armor::setMaterial(int pMaterial)
{
	if (pMaterial >= CLOTH && pMaterial <= NO_MAT)
	{
		material = pMaterial;
	}
	else
	{
		material = NO_MAT;
		std::cerr << "ERROR in setting material " << pMaterial << std::endl; // throw error?
	}

}

/******************************************************************************
*
******************************************************************************/
void Armor::setResistance(int pResistance)
{
	if (pResistance >= 0)
	{
		resistance = pResistance;
	}
	else
	{
		pResistance = 0;
		std::cout << "ERROR in setting resistance" << pResistance << std::endl; // Throw error?
	}
}

/******************************************************************************
*
******************************************************************************/
void Armor::print()
{
	std::string materials[4] = { "Cloth", "Leather", "Metal", "No Material" };
	std::string types[4] = { "Head", "Chest", "Legs", "No Type" };
	std::cout << "Name: " << name
		<< "\nType: " << types[type]
		<< "\nMaterial: " << materials[material]
		<< "\nResistance: " << resistance
		<< "\nStrength: " << strength
		<< "\nIntellignece: " << intelligence
		<< "\nAgility: " << agility << std::endl << std::endl;
}