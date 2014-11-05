#include "Character.h"
#include "Sword.h"
#include "Mace.h"
#include <iostream>



int main(int argc, char* argv[])
{
	Item* inventory[2];
	inventory[0] = new Sword;
	inventory[1] = new Mace;

	inventory[0]->print();
	inventory[1]->print();

	Character player;
	Weapon * pItem = new Sword;
	player.setWeapon(pItem);
	player.getWeapon()->print();



	while (true)
	{
		//pull keyboard
		//update characters
		//draw
		player.draw();
	}

	return 0;
}