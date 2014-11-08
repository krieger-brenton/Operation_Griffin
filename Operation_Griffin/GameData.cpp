#include "GameData.h"



GameData::GameData(){
	player = new Player();
	player->setMe('@');
	for (int i = 0; i < 10; i++)
	{
		enemy = new Enemy();
		enemy->setMe('E');
		enemies.push_back(enemy);
	}
}