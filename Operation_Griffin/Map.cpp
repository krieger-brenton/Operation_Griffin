#include "Map.h"
#include <iostream>
#include <iomanip>

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
			}
			else
			{
				if (x == 0 || x == MAX_X - 1)
					std::cout << '-' << std::setw(3);
				else if (y == 0 || y == MAX_Y - 1)
					std::cout << '|' << std::setw(3);
				else
					std::cout << '.' << std::setw(3);
			}
		}
		std::cout << std::endl;
	}
}

/**/
void Map::addCharacter(Character* pCharacter, int pX, int pY)
{
	map[pX][pY].push_back(pCharacter);
}