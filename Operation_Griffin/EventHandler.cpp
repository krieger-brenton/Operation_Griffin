#include "EventHandler.h"
#include <iostream>
#include <sstream>
#include "GameData.h"
bool EventHandler::addEvent(Event* event)
{
	if (event != NULL)
	{
		events.push_back(event);
		return true;
	}
	else
		return false;
}

bool EventHandler::resolveEvents()
{
	if (GameData::instance()->fResetMsg)
	{
		GameData::instance()->fResetMsg = false;
		GameData::instance()->message = "                                                                     ";
	}
	while (events.size())
	{
		//events.front()->print();
		//deal with event
		if (events.front()->getType() == 'K')
			resolveKeyEvent(events.front());
		else if (events.front()->getType() == 'C')
			resolveCombatEvent(events.front());
		else if (events.front()->getType() == 'M')
			resolveMoveEvent(events.front());
		else
			std::cerr << "Event Type \"" << events.front()->getType() << "\" cannot be handled." << std::endl;
		events.erase(events.begin());
	}
	if (!events.size())
		return true;
	else
		return false;
}

void EventHandler::resolveKeyEvent(Event* event) {
	KeyEvent* keyEvent = static_cast<KeyEvent*>(event);

	if (keyEvent->getKey() == "VK_UP")
	{
		//std::cerr << "Up was pressed" << std::endl;
		GameData::instance()->player->setDirection(NORTH);
		GameData::instance()->map.movePlayer(1, 0);
		GameData::instance()->map.moveEnemies();
	}
	if (keyEvent->getKey() == "VK_LEFT")
	{
		//std::cerr << "Left was pressed" << std::endl;
		GameData::instance()->player->setDirection(WEST);
		GameData::instance()->map.movePlayer(0, -1);
		GameData::instance()->map.moveEnemies();
	}
	if (keyEvent->getKey() == "VK_RIGHT")
	{
		//std::cerr << "Right was pressed" << std::endl;
		GameData::instance()->player->setDirection(EAST);
		GameData::instance()->map.movePlayer(0, 1);
		GameData::instance()->map.moveEnemies();
	}
	if (keyEvent->getKey() == "VK_DOWN")
	{
		//std::cerr << "Down was pressed" << std::endl;
		GameData::instance()->player->setDirection(SOUTH);
		GameData::instance()->map.movePlayer(-1, 0);
		GameData::instance()->map.moveEnemies();
	}
	if (keyEvent->getKey() == "VK_SPACE")
	{
		int x = GameData::instance()->player->getPoint().getX();
		int y = GameData::instance()->player->getPoint().getY();
		switch (GameData::instance()->player->getDirection())
		{
		case 0:
			y++;
			break;
		case 1:
			x++;
			break;
		case 2:
			y--;
			break;
		case 3:
			x--;
			break;
		}
		Character* defender = GameData::instance()->map.enemyAtPoint(x, y);
		if (defender)
		{
			Event* event = new CombatEvent(defender, GameData::instance()->player);
			addEvent(event);
		}
		else {
			GameData::instance()->message = "You viciously attack the air to the ";
			switch (GameData::instance()->player->getDirection())
			{
			case 0:
				GameData::instance()->message += "NORTH";
				break;
			case 1:
				GameData::instance()->message +=  "EAST";
				break;
			case 2:
				GameData::instance()->message += "SOUTH";
				break;
			case 3:
				GameData::instance()->message += "WEST";
				break;
			}
			GameData::instance()->message += "              ";
		}
	}
	/*
	if (GetAsyncKeyState('D') & 0x8000)
	{
		std::cerr << "d was pressed" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		std::cerr << "w was pressed" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		std::cerr << "a was pressed" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		std::cerr << "s was pressed" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	*/
}

void EventHandler::resolveCombatEvent(Event* event) {
	CombatEvent* combatEvent = static_cast<CombatEvent*>(event);

	//get the damage of the weapon the player is using
	int maxDamage = combatEvent->getAttacker()->getWeapon()->getDamage();
	
	//get the main stat of the weapon and apply the appropraite player stat to the damage
	switch (combatEvent->getAttacker()->getWeapon()->getStat())
	{
		case 'S':
			maxDamage *= combatEvent->getAttacker()->getStr();
			break;
	}
	MTRand_int32 rand;
	int damage = (rand() % maxDamage) + 1;
	
	//critical 
	if (rand() % 100 > 95)
		damage = maxDamage * 1.5;
	
	/*  THIS IS CAUSING CRASHES :(
	//get the defense of the defender
	int def = 0;
	for (int i = 0; i < 3; i++)
		def += combatEvent->getDefender()->getArmor()[i]->getResistance();

	//adjust the damage
	damage = damage - def;
	*/

	//apply the damage
	combatEvent->getDefender()->setHealth(combatEvent->getDefender()->getHealth() - damage);
	GameData::instance()->message = "You attack an enemy to the ";
	
	switch (GameData::instance()->player->getDirection())
	{
	case 0:
		GameData::instance()->message += "NORTH";
		break;
	case 1:
		GameData::instance()->message += "EAST";
		break;
	case 2:
		GameData::instance()->message += "SOUTH";
		break;
	case 3:
		GameData::instance()->message += "WEST";
		break;
	}
	GameData::instance()->message += " for ";
	std::ostringstream oss;
	oss << damage;
	GameData::instance()->message += oss.str();
	GameData::instance()->message += " damage!                ";
}

bool EventHandler::resolveMoveEvent(Event* event)
{
	MoveEvent* moveEvent = static_cast<MoveEvent*>(event);
	GameData::instance()->map.moveEnemy(moveEvent->getEnemy(), moveEvent->getMove());
	return true;
}