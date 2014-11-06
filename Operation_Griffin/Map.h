#ifndef MAP_H
#define MAP_H
#include "Character.h"
#include <vector>

#define MAX_X 10
#define MAX_Y 10

class Map
{
public:
	Map();
	void draw();
	void addCharacter(Character* pCharacter, int pX, int pY);
	std::vector<Character*> map[MAX_X][MAX_Y];
	void movePlayer(int xOffset, int yOffset);
private:

};


#endif /* MAP_H */