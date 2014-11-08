/******************************************************************************
* CLASS ARMOR
* Member Varaibles:
* 	int type - The part of the body were the Armor can be equiped. (e.g., Head,
		Chest, Legs)
*	int material - The material the Armor is made of. (e.g., Cloth, Leather, 
		Metal)
*	int resistance - Statistical value to calculate how much damage the Armor
		can negate.
*
* Contructors:
* default constructor:
* Armor() - Sets everything to zero or NO_TYPE/NO_MAT
* Other constructors:
* Armor(int,int,int) - calls the parent class, Item's default constructor then
*	sets Armor's member variables to the parameters using the class's mutators
* constructor (int,int,int,int,int,int) - calls Item's non-default constructor
*	and then sets Armor's member variables to the parameters using the class's
*	mutator functions.
*
* Other Functions:
*	Accessors: simply returns the integer values for each member variable.
*	void getType()
*	void getMaterial() 
*	void getResistance()
*	Mutators:
*	void setType(int pType) - If pType is not within 0 and 3(NO_TYPE) it is
		set to 3(NO_TYPE) and an error is displayed.
*	void setMaterial(int pMaterial) - If pMaterial is not within 0 and 3(NO_MAT)
		it is set to 3(NO_MAT) and an error is displayed.
*	void setResistance(int pResistance) - If pResistance is negative then 
		resistance is set to zero and an error is displayed.
*	void print() - Virtual function, overwritten to show all member and 
		inherited variables.
******************************************************************************/

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

enum ARMORTYPE {HEAD, CHEST, LEGS, NO_TYPE};
enum MATERIAL {CLOTH, LEATHER, METAL, NO_MAT};


/**********************************************
* Class Armor
* Subclass of Item
**********************************************/
class Armor : public Item
{
public:
	//constructors
	Armor() : Item(), type(NO_TYPE), material(NO_MAT), resistance(0) { setName("ARMOR"); }
	Armor(int pType, int pMaterial, int pResistance);
	Armor(int pType, int pMaterial, int pResistance, int pStrength,
		int pIntelligence, int pAgility);
	
	//accessors
	void setType(int pType);
	void setMaterial(int pMaterial);
	void setResistance(int pResistance);

	//mutators
	inline int getType() { return type; }
	inline int getMaterial() { return material; }
	inline int getResistance() { return resistance; }

	//display
	void print() sealed;

private:
	int type;
	int material;
	int resistance;
};

#endif /* ARMOR_H */