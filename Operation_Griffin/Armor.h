#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

enum ARMORTYPE {HEAD, CHEST, LEGS, NO_TYPE};
enum MATERIAL {CLOTH, LEATHER, METAL, NO_MAT};

class Armor : public Item
{
public:
	Armor() : Item(), type(NO_TYPE), material(NO_MAT), resistance(0) {}
	Armor(int pType, int pMaterial, int pResistance);

	void setType(int pType);
	void setMaterial(int pMaterial);
	void setResistance(int pResistance);

	inline int getType() { return type; }
	inline int getMaterial() { return material; }
	inline int getResistance() { return resistance; }

	void print() sealed;

private:
	int type;
	int material;
	int resistance;
};









#endif /* ARMOR_H */