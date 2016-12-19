#ifndef INVENTORY_H
#define INVENTORY_H
#include "./Item.h"

class Inventory{
public:
	void display();
	void sort(string method);

	void getMaxStorage();
	int setMaxStorage()const;

	void pickupItem(const Item*, Inventory*);
	void dropItem(const Item*);
	void placeItem(const Item*, Inventory*);
private:
	int maxStorage;
	vector<Item*> storage;
};
#endif INVENTORY_H