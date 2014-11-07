#include "Character.h"
#include "Sword.h"
#include "Mace.h"
#include "Map.h"
#include "Armor.h"
#include "mtrand.h"
#include "Store.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include "GameData.h"

//initialize our Singleton pointers to NULL
GameData *GameData::s_instance = NULL;

/*******************************************
* Main.
* 'nough said.
********************************************/
int main(int argc, char* argv[])
{
	std::cout << "TESTING INVENTORY" << std::endl;
	Item* inventory[3];
	inventory[0] = new Sword;
	inventory[1] = new Mace;
	inventory[2] = new Armor(HEAD, LEATHER, 1);

	inventory[0]->print();
	inventory[1]->print();
	inventory[2]->print();

	std::cout << std::endl << "TESTING CHARACTER" << std::endl;
	Weapon * pItem = new Sword;
	GameData::instance()->player.setWeapon(pItem);
	GameData::instance()->player.setArmor(new Armor(LEGS, METAL, 2));
	GameData::instance()->player.getWeapon()->print();
	GameData::instance()->player.getArmor()[LEGS]->print();
	GameData::instance()->player.setMe('@');

	std::cout << std::endl << "TESTING STORE" << std::endl;
	// Store testing
	GameData::instance()->store.generateItems();
	GameData::instance()->store.showItems();


	/* START OF PRNG TESTING
	MTRand_int32 rand;
	unsigned long s = time(0); // I think this is giving me the current time. 
	rand.seed(s);

	for (int i = 0; i < 100; ++i)
	{
		std::cout << rand() << ' ';
		if (i % 5 == 4)
			std::cout << std::endl;
	}
	END OF PRNG TESTING*/

	//int pause;
	//std::cin >> pause;

	

	GameData::instance()->map.addCharacter(&GameData::instance()->player, 2, 2);
	GameData::instance()->map.draw();
	while (true)
	{
		//poll keyboard
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			//std::cerr << "Up was pressed" << std::endl;
			GameData::instance()->map.movePlayer(1, 0);
			GameData::instance()->map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{

			//std::cerr << "Left was pressed" << std::endl;
			GameData::instance()->map.movePlayer(0, -1);
			GameData::instance()->map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			//std::cerr << "Right was pressed" << std::endl;
			GameData::instance()->map.movePlayer(0, 1);
			GameData::instance()->map.draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			//std::cerr << "Down was pressed" << std::endl;
			GameData::instance()->map.movePlayer(-1, 0);
			GameData::instance()->map.draw();
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
	}
	return 0;
}