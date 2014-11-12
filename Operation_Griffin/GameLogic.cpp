#include "GameLogic.h"
#include "Event.h"
#include <chrono>
#include <thread>
#include <Windows.h>

void GameLogic::pollKeyboard(){
	Event * event = NULL;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		event = new KeyEvent("VK_UP");
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		event = new KeyEvent("VK_LEFT");
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		event = new KeyEvent("VK_RIGHT");
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		event = new KeyEvent("VK_DOWN");
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		event = new KeyEvent("VK_SPACE");
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