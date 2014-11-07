#include "Item.h"
#include <iostream>

/*******************************
*
*******************************/
Item::Item(int pStrength, int pIntelligence, int pAgility)
{
	setStrength(pStrength);
	setIntelligence(pIntelligence);
	setAgility(pAgility);
}

/*******************************
*
*******************************/
void Item::setStrength(int pStrength)
{
	if (pStrength >= 0)
		strength = pStrength;
	else
		;//throw error?
}

/*******************************
*
*******************************/
void Item::setIntelligence(int pIntelligence)
{
	if (pIntelligence >= 0)
		intelligence = pIntelligence;
	else
		;//throw error?
}

/*******************************
*
*******************************/
void Item::setAgility(int pAgility)
{
	if (pAgility >= 0)
		agility = pAgility;
	else
		;//throw error?
}

/*******************************
*
*******************************/
void Item::print()
{
	std::cout << "Name: " << name
		<< "\nStrength: " << strength
		<< "\nIntellignece: " << intelligence
		<< "\nAgility: " << agility;
}