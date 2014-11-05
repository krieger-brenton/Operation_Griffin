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
			if (map[x][y].begin != NULL)
				std::cout << map[x][y][0];
		}
	}
}

/**/
void Map::addCharacter(Character* pCharacter, int pX, int pY)
{

}