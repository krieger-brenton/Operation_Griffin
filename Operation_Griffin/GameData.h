#pragma once
#include "Character.h"
#include "Map.h"
#include "Store.h"
#include <vector>
#include <string>


/**********************************************
* Class GameData
* A Singleton class to hold all instances of
* Game objects.
**********************************************/
class GameData
{
public:
	//our singleton instance
	static GameData * instance() {
		if (!s_instance)
			s_instance = new GameData();
		return s_instance;
	}
	Character* player;
	Character* enemy;
	std::vector<Character*> enemies;
	Map map;
	Store store;
	std::string message;
	bool fResetMsg;
private:
	static GameData *s_instance;
	GameData();
};

