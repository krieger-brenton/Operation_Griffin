#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
	Item() : strength(0), intelligence(0), agility(0), name("ITEM") {}
	Item(int strength, int intelligence, int agility);
	int getStrength() { return strength; }
	int getIntelligence() { return intelligence; }
	int getAgility() { return agility; }
	void setStrength(int pStrength);
	void setIntelligence(int pIntelligence);
	void setAgility(int pAgility);
	void setName(std::string pName) { name = pName; } // TODO: this is sloppy.
	virtual void print();
protected:
	int strength;
	int intelligence;
	int agility;
	std::string name;

};

#endif /* ITEM_H */