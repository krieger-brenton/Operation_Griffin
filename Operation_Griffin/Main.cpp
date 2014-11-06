#include "Character.h"
#include "Sword.h"
#include "Mace.h"
#include "Map.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>




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
		map.draw();
		i++;
	while (true)
	{
		//poll keyboard
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			std::cerr << "Up was pressed" << std::endl;
			map.movePlayer(1, 0);
			map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{

			std::cerr << "Left was pressed" << std::endl;
			map.movePlayer(0, -1);
			map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			std::cerr << "Right was pressed" << std::endl;
			map.movePlayer(0, 1);
			map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			std::cerr << "Down was pressed" << std::endl;
			map.movePlayer(-1, 0);
			map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			std::cerr << "Space was pressed" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			std::cerr << "d was pressed" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			std::cerr << "w was pressed" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			std::cerr << "a was pressed" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			std::cerr << "s was pressed" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		i++; //my stupid pause
	}
	return 0;
}