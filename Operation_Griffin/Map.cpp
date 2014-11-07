#include "Map.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

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
	system("CLS"); //windows only
	bool fDrawn = false;
	//You have to draw the rows in reverse order to follow x,y coords
	for (int x = MAX_X - 1; x > -1; x--)
	{
		fDrawn = false;
		for (int y = 0; y < MAX_Y; ++y)
		{
			fDrawn = false;
			//when we find a vector with something in it!
			for (std::vector<Character*>::iterator it = map[x][y].begin(); it != map[x][y].end(); it++)
			{
				if (*it != NULL) 
				{
					(*it)->draw();
					fDrawn = true;
				}
				
			}
			if (!fDrawn)
			{
				//todo: get some randomly generated terrain in here
				if (x == 0 || x == MAX_X - 1)
					std::cout << '-' << std::setw(3);
				else if (y == 0 || y == MAX_Y - 1)
					std::cout << '|' << std::setw(3);
				else
					std::cout << '.' << std::setw(3);
				fDrawn = false;
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
	map[pX][pY].push_back(pCharacter);
}

/****************************************************
* Move a player
*****************************************************/
void Map::movePlayer(int xOffset, int yOffset)
{
	bool fDuplicate = false;
	std::vector<Character*> moved;
	Character* pChar = NULL;
	moved.push_back(pChar);

	for (int x = MAX_X - 1; x > -1; x--)
	{
		fDuplicate = false;
		for (int y = 0; y < MAX_Y; ++y)
		{
			fDuplicate = false;
			for (auto it = map[x][y].begin(); it != map[x][y].end(); it++)
			{
				fDuplicate = false;
				if (*it != NULL && //make sure we're moving a real player and we're within bounds 
					x + xOffset < MAX_X  && x + xOffset > -1 &&
					y + yOffset < MAX_Y  && y + yOffset > -1)
				{
/*	Sometimes I'm an idiot.  This will work well for squad based combat because it moves every player in the same direction. 
    But we're not making a squad based game. Silly, Silly me.

					//check to make sure we haven't already moved this player
					for (auto movedPlayer = moved.begin(); movedPlayer != moved.end(); movedPlayer++)
					{
						if (*it == *movedPlayer)
						{
							fDuplicate = true;
							//std::cerr << *it << " " << *movedPlayer;
						}
					}	
					if (!fDuplicate)
					{
					*/
						addCharacter(*it, x + xOffset, y + yOffset);
						//moved.push_back(*it);
						map[x][y].erase(it);
						return;
						//it = map[x][y].begin();
						//std::cerr << "X:" << x << " Y:" << y << " xOffset:" << xOffset << " yOffset:" << yOffset << std::endl;
					//}
				}
			}
		}
	}
}