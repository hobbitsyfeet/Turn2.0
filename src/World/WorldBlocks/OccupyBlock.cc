#include "Unit.h"
#include "WorldBlocks/OccupyBlock.h"
#include "WorldBlocks/WorldBlock.h"
#include <fstream>
#include<iostream>

using namespace std;

Unit* OccupyBlock::getUnit(){
	return this->OccupiedUnit;
}

