#ifndef ITEM_H
#define	ITEM_H

#include <iostream>
using namespace std;

class Item{
public:
	Item(string = "Stick", double = 1);
	string getName();
	double getWorth();

	void setName(string newName);

	//virtual void use() = 0;

protected:
	string name;
	double worth;
};

#endif //ITEM_H