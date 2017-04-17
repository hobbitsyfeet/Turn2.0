#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

#include "Coord.h"
#include "Unit.h"
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
	string getName();
	//void setUnitNull();

protected:
	Unit* OccupiedUnit;
	string format;
	string name;
	char type;
	bool collision;
private:
};

class DeepWater : public WorldBlock{
public:
	DeepWater();
};

class ShallowWater : public WorldBlock{
public:
	ShallowWater();
};

class Grass : public WorldBlock{
public:
	Grass();
};

class TallGrass : public WorldBlock{
public:
	TallGrass();
};

class Lava : public WorldBlock{
public:
	Lava();
};


#endif //WORLDBLOCK_H
