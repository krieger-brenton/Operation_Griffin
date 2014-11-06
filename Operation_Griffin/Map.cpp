#include "Map.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

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
	system("CLS");
	for (int x = MAX_X - 1; x > -1; x--)
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

void Map::movePlayer(int xOffset, int yOffset)
{
	for (int x = MAX_X - 1; x > -1; x--)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			if (map[x][y].back() != NULL)
			{
				if (x + xOffset < MAX_X  && x + xOffset > -1 &&
					y + yOffset < MAX_Y  && y + yOffset > -1)
				{
					Character* pChar = map[x][y].back();
					map[x][y].pop_back();
					addCharacter(pChar, x + xOffset, y + yOffset);
					//std::cerr << "X:" << x << " Y:" << y << " xOffset:" << xOffset << " yOffset:" << yOffset << std::endl;
					return;
				}
			}
		}
	}
}