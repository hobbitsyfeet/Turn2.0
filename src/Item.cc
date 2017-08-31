#include "Item.h"

using namespace std;

//Item functions
/*
Item::Item(string Name, double Worth, int Weight){
	name = Name;
	worth = Worth;
	weight = Weight;
}*/

string Item::getName() const{
	return name;
}

double Item::getWorth() const{
	return worth;
}
int Item::getWeight() const{
return weight;
}

void Item::setWorth(double newWorth){
	worth = newWorth;
}

void Item::setName(string newName){
	name = newName;
}

void Item::setWeight(int newWeight){
	weight = newWeight;
}

//Consumable
Consumable::Consumable(string Name, double Worth, int Weight, int Effect){
	name = Name;
	worth = Worth;
	weight = Weight;
	effect = Effect;
}
int Consumable::getEffect(){
	return effect;
}

//Armour
Armour::Armour(string Name, double Worth, int Weight, int Defence, int Slot){
	name = Name;
	worth = Worth;
	weight = Weight;
}

//Weapon
Weapon::Weapon(string Name, double Worth, int Weight, int Damage, int Hands, int Range){
	name = Name;
	worth = Worth;
	weight = Weight;
	damage = Damage;
	hands = Hands;
	range = Range;
}
//Misc
Misc::Misc(string Name, double Worth, int Weight){
	name = Name;
	worth = Worth;
	weight = Weight;
}
