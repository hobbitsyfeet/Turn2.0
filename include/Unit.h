#ifndef UNIT_H
#define UNIT_H
#include "Combat.h"

class Unit{

public:
	string getName()const;
	void setName(string);

	int getHP()const;
	void setHP();

	int getMaxHP()const;
	void setMaxHP();

	int getMana()const;
	void setMana();

	int getMaxMana()const;
	void setMaxMana();

private:
	string name;
	int HP, maxHP;
	int mana, maxMana;
};

#endif UNIT_H