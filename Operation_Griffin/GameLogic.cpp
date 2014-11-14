#include "GameLogic.h"
#include "GameData.h"
#include "Event.h"
#include <chrono>
#include <thread>
#include <Windows.h>

void GameLogic::pollKeyboard(){
	Event * event = NULL;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		event = new KeyEvent("VK_UP");
		GameData::instance()->fResetMsg = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		event = new KeyEvent("VK_LEFT");
		GameData::instance()->fResetMsg = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		event = new KeyEvent("VK_RIGHT");
		GameData::instance()->fResetMsg = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		event = new KeyEvent("VK_DOWN");
		GameData::instance()->fResetMsg = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		event = new KeyEvent("VK_SPACE");
		GameData::instance()->fResetMsg = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
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
	if (event)
		ev.addEvent(event);
}

void GameLogic::update()
{
	GameData::instance()->player->update();
	for (auto enemy : GameData::instance()->enemies)
		if (enemy != NULL)
			enemy->update();
	for (int i = 0; i < GameData::instance()->enemies.size(); i++)
		if (GameData::instance()->enemies[i] && !GameData::instance()->enemies[i]->isAlive())
		{
			GameData::instance()->enemies[i] = NULL;
		}
}

void GameLogic::draw()
{
	GameData::instance()->map.draw();
	std::cout << GameData::instance()->message << std::endl;
	

}