#include "EventHandler.h"

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
		events.front()->print();
		//deal with event
		events.erase(events.begin());
	}
	if (!events.size())
		return true;
	else
		return false;
}