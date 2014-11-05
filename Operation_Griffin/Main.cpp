#include "Character.h"
#include "Sword.h"
#include "Mace.h"
#include "Map.h"
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
	player.setMe('@');

	Map map;
	map.addCharacter(&player, 2, 2);
	int i = 0;
	while (i == 0)
	{
		//pull keyboard
		//update characters
		//draw
		map.draw();
		i++;
	}

	while (true)
	{
		i++; //my stupid pause
	}
	return 0;
}