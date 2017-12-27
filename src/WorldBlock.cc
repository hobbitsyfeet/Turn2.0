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
	OccupiedUnit = NULL;
	name = "Grass";
	format = green();
	type = ',';
	collision = false;
}

TallGrass::TallGrass(){

	OccupiedUnit = NULL;
	name = "Tall Grass";
	format = bold() + green();
	type = ';';
	collision = false;
}

ShallowWater::ShallowWater(){

	OccupiedUnit = NULL;
	name = "Shallow Water";
	format = lightBlue();
	type = '~';
	collision = false;
}

/** Inacessable Terrain **/
DeepWater::DeepWater(){
	
	OccupiedUnit = NULL;
	name = "Deep Water";
	format = blue();
	type = '~';
	collision = true;
}

Lava::Lava(){
	OccupiedUnit = NULL;
	name = "Lava";
	format = bold() + red();
	type = '~';
	collision = true;
}
