#ifndef UNIT_H
#define UNIT_H

//#include "Combat.h"
#include <iostream>

using namespace std;

class Unit{

public:
	string getName()const;
	void setName(string);

	int getHP()const;
	void setHP(int);

	int getMaxHP()const;
	void setMaxHP(int);

	int getMana()const;
	void setMana(int);

	int getMaxMana()const;
	void setMaxMana(int);

private:
	string name;
	int HP, maxHP;
	int mana, maxMana;
};

#endif //UNIT_H