#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword() : Weapon() { setName("SWORD"); }
private:

};

#endif /* SWORD_H */