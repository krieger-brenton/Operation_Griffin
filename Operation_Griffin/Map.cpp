#include "Map.h"
#include <iostream>

/**/
Map::Map()
{
	Character* pPlayer = NULL;
	for (int x = 0; x < MAX_X; ++x)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			map[x][y].push_back(pPlayer);
		}
	}
}

/**/
void Map::draw()
{
	for (int x = 0; x < MAX_X; ++x)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			if (map[x][y].back() != NULL)
			{
				map[x][y].back()->draw();
				//std::cerr << "I drew it!" << std::endl;
			}
			else
				std::cout << '.';
		}
		std::cout << std::endl;
	}
}

/**/
void Map::addCharacter(Character* pCharacter, int pX, int pY)
{
	map[pX][pY].push_back(pCharacter);
}