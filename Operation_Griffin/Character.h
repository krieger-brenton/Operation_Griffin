#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armor.h"
#include "CPoint.h"
#define PLAYER '@'

enum DIRECTION {NORTH, EAST, SOUTH, WEST};

class Character
{
public:
	Character() : me(PLAYER) {}
	void setWeapon(Weapon* pWeapon);
	void setArmor(Armor* pArmor);
	void setDirection(int pDirection);
	int getDirection() { return direction; }
	Weapon* getWeapon() { return weapon; }
	Armor** getArmor() { return armor; }
	void draw();
	char getMe() { return me; }
	void setMe(char a) { me = a; }
	virtual char type() { return 'C'; }
	//void update();
	//void attack();
private:
	char me;
	CPoint location;
	int direction;
	int Health;
	int Strength;
	int Intelligence;
	int Agility;
	Weapon* weapon;
	Armor* armor[3];
};

class Player : public Character
{
public:
	Player() : Character(){};
	virtual char type() { return 'P'; }
};

class Enemy : public Character
{
public:
	Enemy() : Character(){};
	virtual char type() { return 'E'; }
};

#endif /* CHARACTER_H */