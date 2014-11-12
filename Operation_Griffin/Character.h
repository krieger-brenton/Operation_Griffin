#pragma once
#include "Weapon.h"
#include "Armor.h"
#include "CPoint.h"
#define PLAYER '@'

enum DIRECTION { NORTH, EAST, SOUTH, WEST };

class Character
{
public:
	Character() : me(PLAYER) {}
	void setWeapon(Weapon* pWeapon);
	void setArmor(Armor* pArmor);
	void setDirection(int pDirection);
	void setHealth(int h){ Health = h; };
	CPoint & getPoint() { return location; }
	int  getHealth(){ return Health; }
	int getDirection() { return direction; }
	Weapon* getWeapon() { return weapon; }
	Armor** getArmor() { return armor; }
	void draw();
	char getMe() { return me; }
	void setMe(char a) { me = a; }
	virtual char type() { return 'C'; }
	std::string getName() { return name; }
	void setName(std::string newName) { name = newName; }
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
	std::string name;
};

class Player : public Character
{
public:
	Player() : Character() { setName("Player"); }
	virtual char type() { return 'P'; }
};

class Enemy : public Character
{
public:
	Enemy() : Character() { setName("Enemy"); }
	virtual char type() { return 'E'; }
};
