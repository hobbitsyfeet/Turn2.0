#include "Item.h"

using namespace std;

Item::Item(string Name, double Worth){
	name = Name;
	worth = Worth;
}

string Item::getName(){
	return name;
}

double Item::getWorth(){
	return worth;
}

void Item::setName(string newName){
	name = newName;
}