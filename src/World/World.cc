#include "World.h"
#include "Unit.h"
#include "Coord.h"
#include "WorldBlocks/WorldBlock.h"
#include "WorldBlocks/Grass.h"
#include <vector>

void World::generate(){
	chart.resize( size.getY()+1, vector<WorldBlock*>(size.getX()) );
	int x = 0, y = size.getY()+1;

	vector<vector<WorldBlock*> >::iterator row;
	vector<WorldBlock*>::iterator col;

	WorldBlock* currentBlock;


	for(row = chart.end(); row > chart.begin() ; row--){
		for(col = row->begin(); col< row->end(); col++){
			x++;

			*col = new Grass;
			currentBlock = *col;

			//cout<<x<<','<<y<<'|';
			currentBlock->location.setX(x);
			currentBlock->location.setY(y);
		}//end Collumn
		y--;
		x=0;
		cout<<endl;
	}//end Row
}



void World::display(){
	vector<vector<WorldBlock*> >::iterator row;
	vector<WorldBlock*>::iterator col;

	for(row = chart.end(); row > chart.begin() ; row--){
		for(col = row->begin(); col< row->end(); col++){
			(*col)->display();
			cout<<' ';
		}
		cout<<endl;
	}
}

WorldBlock* World::getWorldBlock(Coord blockLocation){
	vector<vector <WorldBlock*> >::iterator row = chart.begin() + blockLocation.getY();
	vector<WorldBlock*> ::iterator col = row->begin() + blockLocation.getX()-1;
	return *col;
}