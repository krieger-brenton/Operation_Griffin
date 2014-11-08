#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Event.h"
#include <vector>

class EventHandler
{
public:
	bool addEvent(Event* event);
	bool resolveEvents();
private:
	std::vector<Event*> events;
};
#endif /* EVENTHANDLER_H */