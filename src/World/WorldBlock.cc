#include "WorldBlock.h"
#include "Unit.h"
#include "Colours.h"

#include <fstream>
#include <iostream>
using namespace std;

void WorldBlock::saveWorldBlock( ofstream& fout ){
	fout<<' '<<name;
}

void WorldBlock::loadWorldBlock( ifstream& fin ){
	fin>>name;
}

void WorldBlock::display(){

	if(OccupiedUnit == NULL){
		cout<<format<<type<<"\033[0m";
	}
	else if(OccupiedUnit != NULL){
		OccupiedUnit->display();
	}
	//A CASE WE DO NOT WANT
	else{
		cout<<"X";
	}
}

bool WorldBlock::getCollision(){
	return collision;
}

void WorldBlock::setUnit(Unit& currentUnit){
	OccupiedUnit = &currentUnit;
}

Unit* WorldBlock::getUnit(){
	return OccupiedUnit;
}
string WorldBlock::getName(){
	return name;
}

/***********************
*
*	START SUBCLASS DECLARATIONS
*
************************/
/** Accessable terrain **/
Grass::Grass(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "Grass";
	format = effect.green();
	type = ',';
	collision = false;
}

TallGrass::TallGrass(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "Tall Grass";
	format = effect.bold() + effect.green();
	type = ';';
	collision = false;
}

ShallowWater::ShallowWater(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "Shallow Water";
	format = effect.lightBlue();
	type = '~';
	collision = false;
}

/** Inacessable Terrain **/
DeepWater::DeepWater(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "Deep Water";
	format = effect.blue();
	type = '~';
	collision = true;
}

Lava::Lava(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "Lava";
	format = effect.bold() + effect.red();
	type = '~';
	collision = true;
}
