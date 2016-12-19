#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "./WorldBlocks/WorldBlock.h"

class World{
public:

	virtual void generate() = 0;
	void display();
	void getInfo(int,int);

	void loadWorld();
	void saveWorld();

private:
vector<vector<WorldBlock*>> chart;
};
#endif //WORLD_H