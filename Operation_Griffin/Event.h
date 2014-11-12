#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Character.h"
class Event
{
public:
	void print() {}
	virtual char getType() { return 'E'; }
private:

};

class KeyEvent : public Event
{
public:
	KeyEvent() : Event() {}
	KeyEvent(std::string keypress) : KeyEvent() { key = keypress; }
	void setKey(std::string keypress) { key = keypress; };
	std::string getKey(){ return key; }
	virtual char getType() { return 'K'; }
private:
	std::string key;
};

class CombatEvent : public Event
{
public:
	CombatEvent() : Event() {}
	CombatEvent(Character* def, Character* atk, Character* dam) : CombatEvent() { defender = def; attacker = atk; damage = dam; }
	virtual char getType() { return 'C'; }
	void setDefender(Character* def) { defender = def; }
	void setAttacker(Character* atk) { attacker = atk; }
	void setDamage(Character* dam)   { damage   = dam; }
	Character* getDefender() { return defender; }
	Character* getAttacker() { return attacker; }
	Character* getDamage()	 { return damage; }
private:
	Character* defender;
	Character* attacker;
	Character* damage;
};


#endif /* EVENT_H */