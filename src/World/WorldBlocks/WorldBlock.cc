#include "WorldBlocks/WorldBlock.h"

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
	cout<<format<<type;
}

bool WorldBlock::getCollision(){
	return collision;
}



