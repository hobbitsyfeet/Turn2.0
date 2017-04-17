#include "Item.h"

using namespace std;

Item::Item(string Name, double Worth){
	name = Name;
	worth = Worth;
}

string Item::getName() const{
	return name;
}

double Item::getWorth() const{
	return worth;
}
void Item::setWorth(double newWorth){
	worth = newWorth;
}

void Item::setName(string newName){
	name = newName;
}
