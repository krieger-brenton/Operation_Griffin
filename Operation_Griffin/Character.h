#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#define PLAYER '@'

class Character
{
public:
	Character() : me(PLAYER) {}
	void setWeapon(Weapon* pWeapon);
	Weapon* getWeapon() { return weapon; }
	void draw();
	char getMe() { return me; }
	//void attack();
private:
	char me;
	//Point location;
	int direction;
	int Health;
	int Strength;
	int Intelligence;
	int Agility;
	Weapon* weapon;
	//Armor* armor[3];
};


#endif /* CHARACTER_H */