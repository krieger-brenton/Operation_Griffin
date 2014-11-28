#include "Character.h"
#include "GameData.h"
#include "GameLogic.h"

//This should just move the enemies to the player.
void Enemy::update()
{
	Character* player = GameData::instance()->player;
	int xToAdd = 0;
	int yToAdd = 0;
	int diffX = getPoint().getX() - player->getPoint().getX();
	int diffY = getPoint().getY() - player->getPoint().getY();

	if (diffX > 0)
	{
		xToAdd = -1;
	}
	else  if (diffX == 0)
	{
		xToAdd = 0;
	}
	else
	{
		xToAdd = 1;
	}

	if (diffY > 0)
	{
		yToAdd = -1;
	}
	else  if (diffY == 0)
	{
		yToAdd = 0;
	}
	else
	{
		yToAdd = 1;
	}

	Move move;
	move.startX = this->getPoint().getX();
	move.startY = this->getPoint().getY();
	move.destX = move.startX + xToAdd;
	move.destY = move.startY + yToAdd;

	GameLogic::instance()->ev.addEvent(new MoveEvent(move, this));
	
	return;
}