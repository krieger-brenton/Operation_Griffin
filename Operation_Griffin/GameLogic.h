#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "EventHandler.h"

class GameLogic
{
public:
	//our singleton instance
	static GameLogic * instance() {
		if (!s_instance)
			s_instance = new GameLogic();
		return s_instance;
	}
	void pollKeyboard();
	EventHandler ev;
private:
	GameLogic() {};
	static GameLogic * s_instance;
};

#endif /*GAMELOGIC_H*/