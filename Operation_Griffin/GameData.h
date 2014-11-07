#pragma once
#include "Character.h"
#include "Map.h"
#include "Store.h"
#include <vector>
class GameData
{
public:
	static GameData * instance() {
		if (!s_instance)
			s_instance = new GameData;
		return s_instance;
	}
	Character player;
	std::vector<Character*> otherPlayers;
	std::vector<Character*> enemies;
	Map map;
	Store store;
private:
	static GameData *s_instance;
	GameData() {};
};

