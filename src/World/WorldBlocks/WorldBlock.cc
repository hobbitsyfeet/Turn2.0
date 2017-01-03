#include "WorldBlocks/WorldBlock.h"
#include "Unit.h"

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
		cout<<format<<type;
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