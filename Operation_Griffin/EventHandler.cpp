#include "EventHandler.h"
#include <iostream>
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
	while (events.size())
	{
		//events.front()->print();
		//deal with event
		if (events.front()->getType() == 'K')
			resolveKeyEvent(events.front());
		else if (events.front()->getType() == 'C')
			resolveCombatEvent(events.front());
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
		GameData::instance()->map.draw();
	}
	if (keyEvent->getKey() == "VK_LEFT")
	{
		//std::cerr << "Left was pressed" << std::endl;
		GameData::instance()->player->setDirection(WEST);
		GameData::instance()->map.movePlayer(0, -1);
		GameData::instance()->map.moveEnemies();
		GameData::instance()->map.draw();
	}
	if (keyEvent->getKey() == "VK_RIGHT")
	{
		//std::cerr << "Right was pressed" << std::endl;
		GameData::instance()->player->setDirection(EAST);
		GameData::instance()->map.movePlayer(0, 1);
		GameData::instance()->map.moveEnemies();
		GameData::instance()->map.draw();
	}
	if (keyEvent->getKey() == "VK_DOWN")
	{
		//std::cerr << "Down was pressed" << std::endl;
		GameData::instance()->player->setDirection(SOUTH);
		GameData::instance()->map.movePlayer(-1, 0);
		GameData::instance()->map.moveEnemies();
		GameData::instance()->map.draw();
	}
	if (keyEvent->getKey() == "VK_SPACE")
	{
		std::cerr << "Soon, Player will attack ";
		switch (GameData::instance()->player->getDirection())
		{
			case 0:
				std::cerr << "NORTH";
				break;
			case 1:
				std::cerr << "EAST";
				break;
			case 2:
				std::cerr << "SOUTH";
				break;
			case 3:
				std::cerr << "WEST";
				break;
		}
		std::cerr << std::endl;
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
	std::cerr << "Player position: " << GameData::instance()->player->getPoint() << std::endl;


}

void EventHandler::resolveCombatEvent(Event* event) {

}