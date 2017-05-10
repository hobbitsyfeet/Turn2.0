#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector>

class Inventory{
public:
	string display();

	int getMaxStorage() const;
	void setMaxStorage(int);

	void addItem(Item*);
	//Item removeItem(Item*);
private:
	int maxStorage;
	vector<Item*> storage;
};
#endif //INVENTORY_H
