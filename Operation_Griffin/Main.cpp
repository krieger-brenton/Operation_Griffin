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
#include "GameLogic.h"

//initialize our Singleton pointers to NULL
GameData  *GameData:: s_instance = NULL;
GameLogic *GameLogic::s_instance = NULL;
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
	GameData::instance()->player->setWeapon(pItem);
	GameData::instance()->player->setArmor(new Armor(LEGS, METAL, 2));
	GameData::instance()->player->getWeapon()->print();
	GameData::instance()->player->getArmor()[LEGS]->print();
	GameData::instance()->player->setMe('@');

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

	
	MTRand_int32 rand;
	GameData::instance()->map.addCharacter(GameData::instance()->player, 2, 2);
	for (auto enemy : GameData::instance()->enemies)
		GameData::instance()->map.addCharacter(enemy, rand() % 10, rand() % 10);
	GameData::instance()->map.draw();
	while (true)
	{
		//poll keyboard
		GameLogic::instance()->pollKeyboard();
		
		//handle Events
		GameLogic::instance()->ev.resolveEvents();
	}
	return 0;
}