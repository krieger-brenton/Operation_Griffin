#include "Map.h"
#include <iostream>

/**/
Map::Map()
{
	/*for (int x = 0; x < MAX_X; ++x)
	{
	for (int y = 0; y < MAX_Y; ++y)
	{
	//init map
	}
	}*/
}

/**/
void Map::draw()
{
	for (int x = 0; x < MAX_X; ++x)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			if (map[x][y].front() != NULL)
				map[x][y].front()->draw();
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