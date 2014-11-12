#include "Map.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "mtrand.h"
#include <cassert>

/**************************************************
* Constructor
***************************************************/
Map::Map()
{
	Character* pPlayer = NULL;
	for (int x = 0; x < MAX_X; ++x)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			//is there a better way to initialize this?
			map[x][y].push_back(pPlayer);
		}
	}
}

/****************************************************
* Draws the map
*****************************************************/
void Map::draw()
{
	int count = 0;
	system("CLS"); //windows only
	//You have to draw the rows in reverse order to follow x,y coords
	for (int x = MAX_X - 1; x > -1; x--)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			count = 0;
			//when we find a vector with something in it!
			for (std::vector<Character*>::iterator it = map[x][y].begin(); it != map[x][y].end(); it++)
			{
				if (*it != NULL) 
				{
					count++;
				}
				
			}
			if (count > 1)
			{
				std::cout << '*' << std::setw(3);
			}

			if (count == 1)
				for (auto character : map[x][y])
					if (character != NULL)
						character->draw();
			
			if (count == 0)
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

/****************************************************
* Put a character in (x,y) spot
*****************************************************/
void Map::addCharacter(Character* pCharacter, int pX, int pY)
{
	assert(pX < MAX_X);
	assert(pX > -1);
	assert(pY < MAX_Y);
	assert(pY > -1);
	pCharacter->getPoint().setPoint(pX, pY);
	map[pX][pY].push_back(pCharacter);
}

/****************************************************
* Move a player
*****************************************************/
void Map::movePlayer(int xOffset, int yOffset)
{
	for (int x = MAX_X - 1; x > -1; x--)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			for (auto it = map[x][y].begin(); it != map[x][y].end(); it++)
			{
				if (*it != NULL && //make sure we're moving a real player and we're within bounds 
					x + xOffset < MAX_X  && x + xOffset > -1 &&
					y + yOffset < MAX_Y  && y + yOffset > -1)
				{
					if ((*it)->type() != 'E')
					{
						std::cout << (*it)->type() << std::endl;
						addCharacter(*it, x + xOffset, y + yOffset);
						map[x][y].erase(it);
						return;
					}
				}
			}
		}
	}
}

void Map::moveEnemies()
{
	bool fMoved = false;
	MTRand_int32 rand;
	std::vector<Character*> moved;
	for (int x = MAX_X - 1; x > -1; x--)
	{
		for (int y = 0; y < MAX_Y; ++y)
		{
			for (int i = 0; i < map[x][y].size(); i++)
			{
				fMoved = false;
				if (map[x][y][i] != NULL && map[x][y][i]->type() == 'E') //make sure we're moving a real player and we're within bounds 
				{
					for (auto enemy : moved)
					{
						if (map[x][y][i] == enemy)
						{
							fMoved = true;
						}
					}
					if (!fMoved)
					{
						fMoved = true;
						moved.push_back(map[x][y][i]);
						int xOffset = rand() % 2;
						if (rand() % 2 == 1)
							xOffset *= -1;
						int yOffset = rand() % 2;
						if (rand() % 2 == 1)
							yOffset *= -1;
						if (x + xOffset < MAX_X  && x + xOffset > -1 &&
							y + yOffset < MAX_Y  && y + yOffset > -1)
						{
							addCharacter(map[x][y][i], x + xOffset, y + yOffset);
							map[x][y][i] = NULL;
							i = 0;
						}
					}
				}
			}
		}
	}
}