#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Event.h"
#include <vector>

class EventHandler
{
public:
	bool addEvent(Event* event);
	bool resolveEvents();
	void resolveKeyEvent(Event* event);
	void resolveCombatEvent(Event* event);
	bool resolveMoveEvent(Event* event);
private:
	std::vector<Event*> events;
};
#endif /* EVENTHANDLER_H */