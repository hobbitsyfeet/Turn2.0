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

string Unit::statBar(int stat, int maxStat, string colour){
	int numBlocks = 25;
	double percent = (numBlocks * stat / maxStat);
	int numHighlights = percent;
	bool endBar = false;
	Colours format;
	string highlight;
	string lowlight;

	string bar;
	if(colour == "Red"){
		highlight = format.lightRed();
		lowlight = format.red();
	}
	else if(colour == "Gray"){
		highlight = format.gray();
		lowlight = format.darkGray();
	}
	else if (colour == "Blue"){
		highlight = format.cyan();
		lowlight = format.blue();
	}
	else if (colour == "Green"){
		highlight = format.yellow();
		lowlight = format.green();
	}

	for(int index = 0; index < numBlocks; index++){

		if( (numHighlights == 0 && endBar == false)){
			endBar=true;
			bar.append("|");
		}

		if(numHighlights != 0){
			bar.append(format.bold());
			bar.append(highlight);
			numHighlights --;
		}

		else{
			bar.append(lowlight);
		}
		bar.append("_");
		bar.append(format.defaults());
	}

	if(endBar == false)
		bar.append("|");

	return bar;
}

