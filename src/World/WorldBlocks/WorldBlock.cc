#include "../../../include/WorldBlocks/WorldBlock.h"

#include <fstream>
#include <iostream>
using namespace std;

void WorldBlock::saveWorldBlock( ofstream& fout ){
	fout<<' '<<format<<' '<<type<<' '<<collision;
}

void WorldBlock::loadWorldBlock( ifstream& fin ){
	fin>>format>>type;
}

void WorldBlock::display(){
	cout<<format<<type;
}

bool WorldBlock::getCollision(){
	return collision;
}



