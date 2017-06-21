#include "Inventory.h"
#include "Item.h"
#include <string>


string Inventory::display(){

	string display="";
	for (int i = 0; i < storage.size(); i++){
		display += storage[i].first->getName();
			if(storage[i].second > 1){
				display +=" (";
				display += to_string(storage[i].second);
				display += ")";
			}
			display += "\n";
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
	//convert item to pair for inventory storage
	pair<Item*, int> tempItem;
	tempItem.first = newItem;
	tempItem.second = 1;

	//Empty
	if(storage.size() == 0){
		storage.push_back(tempItem);
		return;
	}

	//Larger than anything else
	else if(newItem->getName() > storage.back().first->getName()){
		storage.push_back(tempItem);
	}

	//somewhere in the middle (not smallest or largest)
	else{
		//iterator neccicary for insert function
		vector< pair<Item*, int> >::iterator index;
		pair<Item*, int> accessItem;
		//iterate through inventory
		for(index = storage.begin(); index < storage.end(); index++ ){
			accessItem = *index;
			//if new item is placed, insert
			if(newItem->getName() < accessItem.first->getName()){
				storage.insert(index,tempItem);
				return;
			}
			//if item exists, add to stack
			else if(newItem->getName() == accessItem.first->getName()){
				index->second++;
				return;
			}
		}
	}
}

//void Inventory::removeItem(Item*){}
