#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "WorldBlocks/WorldBlock.h"
#include "Coord.h"

class World{
public:
	Coord size;

	virtual void generate();
	void display();
	WorldBlock getWorldBlock(Coord);

	void loadWorld();
	void saveWorld();

private:
	//int sizeX, sizeY;
	bool fogOfWar;
	//WorldBlock* currentBlock;
	vector<vector<WorldBlock*> > chart;
};
#endif //WORLD_H