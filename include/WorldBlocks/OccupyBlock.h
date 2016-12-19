#ifndef OCCUPYBLOCK_H
#define OCCUPYBLOCK_H

	#include"../Unit.h"
	#include "WorldBlock.h"
	#include <fstream>
	#include<iostream>

using namespace std;

class OccupyBlock : public WorldBlock{
public:
	void saveWorldBlock( ofstream& );
	void loadWorldBlock( ifstream& );

Unit* getUnit();
void setUnit();

protected:
Unit* OccupiedUnit;

};

#endif //WORLDBLOCK_H