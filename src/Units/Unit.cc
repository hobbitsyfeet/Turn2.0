#include "Unit.h"
#include "Colours.h"
#include "Coord.h"
#include <iostream>
using namespace std;

string Unit::getName()const{
	return this->name;
}

void Unit::setName(string newName){
	this->name = newName;
}

int Unit::getHP()const{
	return this->HP;
}

void Unit::setHP(int newHP){
	this->HP = newHP;
}

int Unit::getMaxHP()const{
	return this->maxHP;
}

void Unit::setMaxHP(int newMaxHP){
	this->maxHP = newMaxHP;
}

int Unit::getMana()const{
	return this->mana;
}

void Unit::setMana(int newMana){
	this->mana = newMana;
}

int Unit::getMaxMana()const{
	return this->maxMana;
}

void Unit::setMaxMana(int newMaxMana){
	this->maxMana = newMaxMana;
}

void Unit::move(Coord newCoord){
	location = newCoord;
}

void Unit::display(){
	cout<<"P";
}

