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
	for (int row = 0; row < MAX_X; ++row)
	{
		for (int col = 0; col < MAX_Y; ++col)
		{
			//is there a better wacol to initialize this?
			map[row][col].push_back(pPlayer);
		}
	}
}

/****************************************************
* Draws the map
*****************************************************/
void Map::draw()
{
	int count = 0;
	system("CLS"); //windows onlcol
	//colou have to draw the rows in reverse order to follow row,col coords
	for (int row = MAX_X - 1; row > -1; row--)
	{
		for (int col = 0; col < MAX_Y; ++col)
		{
			count = 0;
			//when we find a vector with something in it!
			for (std::vector<Character*>::iterator it = map[row][col].begin(); it != map[row][col].end(); it++)
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
				for (auto character : map[row][col])
					if (character != NULL)
						character->draw();
			
			if (count == 0)
			{
				if (row == 0 || row == MAX_X - 1)
					std::cout << '-' << std::setw(3);
				else if (col == 0 || col == MAX_Y - 1)
					std::cout << '|' << std::setw(3);
				else
					std::cout << '.' << std::setw(3);
			}
		}
		std::cout << std::endl;
	}
}

/****************************************************
* Put a character in (row,col) spot
*****************************************************/
void Map::addCharacter(Character* pCharacter, int row, int col)
{
	assert(row < MAX_X);
	assert(row > -1);
	assert(col < MAX_Y);
	assert(col > -1);
	pCharacter->getPoint().setPoint(col, row);
	map[row][col].push_back(pCharacter);
}

void Map::addCharacter(Character* pCharacter, CPoint location)
{

}

/****************************************************
* Move a player
*****************************************************/
void Map::movePlayer(int rowOffset, int colOffset)
{
	for (int row = MAX_X - 1; row > -1; row--)
	{
		for (int col = 0; col < MAX_Y; ++col)
		{
			for (auto it = map[row][col].begin(); it != map[row][col].end(); it++)
			{
				if (*it != NULL && //make sure we're moving a real player and we're within bounds 
					row + rowOffset < MAX_X  && row + rowOffset > -1 &&
					col + colOffset < MAX_Y  && col + colOffset > -1)
				{
					if ((*it)->type() != 'E')
					{
						std::cout << (*it)->type() << std::endl;
						addCharacter(*it, row + rowOffset, col + colOffset);
						map[row][col].erase(it);
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
	for (int row = MAX_X - 1; row > -1; row--)
	{
		for (int col = 0; col < MAX_Y; ++col)
		{
			for (int i = 0; i < map[row][col].size(); i++)
			{
				fMoved = false;
				if (map[row][col][i] != NULL && map[row][col][i]->type() == 'E') //make sure we're moving a real player and we're within bounds 
				{
					for (auto enemy : moved)
					{
						if (map[row][col][i] == enemy)
						{
							fMoved = true;
						}
					}
					if (!fMoved)
					{
						fMoved = true;
						moved.push_back(map[row][col][i]);
						int rowOffset = rand() % 2;
						if (rand() % 2 == 1)
							rowOffset *= -1;
						int colOffset = rand() % 2;
						if (rand() % 2 == 1)
							colOffset *= -1;
						if (row + rowOffset < MAX_X  && row + rowOffset > -1 &&
							col + colOffset < MAX_Y  && col + colOffset > -1)
						{
							addCharacter(map[row][col][i], row + rowOffset, col + colOffset);
							map[row][col][i] = NULL;
							i = 0;
						}
					}
				}
			}
		}
	}
}