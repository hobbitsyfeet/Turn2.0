#ifndef ITEM_H
#define	ITEM_H

#include <iostream>
using namespace std;

/** PARENT ITEM **/
class Item{
public:
	//Item(string Name, double worth, int weight);
	string getName() const;
	double getWorth() const;
	int getWeight() const;

	void setName(string newName);
	void setWorth(double newWorth);

	void setWeight(int weight);

	//virtual void use() = 0;

protected:
	string name;
	double worth;
	int weight;
};


/** CHILD CONSUMABLE **/
class Consumable : public Item{
public:
	Consumable(string name, double worth, int weight, int effect);
	int getEffect();
private:
	int effect;
};


/** CHILD ARMOUR **/
class Armour : public Item{
public:
	Armour(string name, double worth, int weight, int defence, int slot);

private:
	int defence;
	int slot;
};


/** CHILD WEAPON **/
class Weapon : public Item{
public:
	Weapon(string name, double worth, int weight, int damage, int hands, int range);
private:
	int damage;
	int hands;
	int range;
};

class Misc : public Item{
public:
	Misc(string name, double worth, int weight);
};

#endif //ITEM_H
