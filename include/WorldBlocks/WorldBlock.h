#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

#include "Coord.h"
#include "../Unit.h"
#include <fstream>
#include<iostream>

using namespace std;

class WorldBlock{
public:
	Coord location;

	void saveWorldBlock( ofstream& );
	void loadWorldBlock( ifstream& );

	void display();

	bool getCollision();

	Unit* getUnit();
	void setUnit(Unit&);
	//void setUnitNull();

protected:
	Unit* OccupiedUnit;
	string format;
	string name;
	char type;
	bool collision;
private:
};

#endif //WORLDBLOCK_H