#ifndef MAP_H
#define MAP_H
#include "Character.h"
#include <vector>
#include "CPoint.h"

#define MAX_X 10
#define MAX_Y 10

/****************************************************
* The game board, or map. 
*****************************************************/
class Map
{
public:
	Map();
	void draw();
	void addCharacter(Character* pCharacter, int pX, int pY);
	void addCharacter(Character* pCharacter, CPoint location);
	std::vector<Character*> map[MAX_X][MAX_Y];
	void movePlayer(int xOffset, int yOffset);
	void moveEnemies();
	Character* enemyAtPoint(int x, int y);
private:

};


#endif /* MAP_H */