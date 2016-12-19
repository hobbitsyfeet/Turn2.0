#include "Unit.h"
#include "WorldBlocks/OccupyBlock.h"
#include "WorldBlocks/WorldBlock.h"
#include <fstream>
#include<iostream>

using namespace std;

void OccupyBlock::saveWorldBlock( ofstream& fout ){

	fout<<" 1"<<' '<<format<<' '<<type<<' '<<collision;
	//this->OccupiedUnit.saveUnit();
}
void OccupyBlock::loadWorldBlock( ifstream& fin){
	//this->WorldBlock::loadWorldBlock();
	//this->OccupiedUnit.loadUnit();
}

Unit* OccupyBlock::getUnit(){
	return this->OccupiedUnit;
}

