#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Character.h"
class Event
{
public:
	void print() {}
	void setType(char c) { type = c; }
	char getType() { return type; }
private:
	char type;

};
#endif /* EVENT_H */

class KeyEvent : public Event
{
public:
	KeyEvent() : Event() { setType('K'); }
	KeyEvent(std::string keypress) : KeyEvent() { key = keypress; }
	void setKey(std::string keypress) { key = keypress; };
	std::string getKey(){ return key; }
private:
	std::string key;
};

class CombatEvent : public Event
{
public:
	CombatEvent() : Event() { setType('C');  }
	CombatEvent(Character* def, Character* atk, Character* dam) : CombatEvent() { defender = def; attacker = atk; damage = dam; }
private:
	Character* defender;
	Character* attacker;
	Character* damage;
};