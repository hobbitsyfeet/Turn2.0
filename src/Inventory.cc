#include "Inventory.h"
#include "Item.h"
#include <string>


string Inventory::display(){
	string display = "";

	vector<Item*>::iterator index;
	vector<Item*>::iterator index2;
	Item* accessItem;
	Item* stackItem;
	int stack = 0;

	//iterate through inventory
	for(index = storage.begin(); index < storage.end(); index++){
		accessItem = *index;
		index2 = index+1;

		//prevents segfault
		if(index2 == storage.end()){
			display += accessItem->getName();
			display += "\n";
			break;
		}

		//valid item at index2
		stackItem = *index2;

		//go through and increment without display
		while(stackItem->getName() == accessItem->getName() && index2 != storage.end()){
			stack++;
			index++;
			accessItem = *index;
			index2 = index+1;
			stackItem = *index2;
		}

		//Display
		display += accessItem->getName();
		if(stack != 0){
			display +="s (";
			display += to_string(stack+1);
			display+=")";
		}
		display +="\n";
		stack=0;
	}
	return display;
}


int Inventory::getMaxStorage() const{
	return maxStorage;
}

void Inventory::setMaxStorage(int newMax){
	maxStorage = newMax;
}

void Inventory::addItem(Item* newItem){
	//Empty
	if(storage.size() == 0){
		storage.push_back(newItem);
		return;
	}

	//Larger than anything else
	else if(newItem->getName() >= storage.back()->getName()){
		storage.push_back(newItem);
	}

	//somewhere in the middle (not smallest or largest)
	else{
		vector<Item*>::iterator index = storage.begin();
		Item* accessItem;
		for(index = storage.begin(); index < storage.end(); index++ ){
			accessItem = *index;
			if(newItem->getName() <= accessItem->getName()){
				storage.insert(index,newItem);
				return;
			}
		}
	}
}

//void Inventory::removeItem(Item*){}
