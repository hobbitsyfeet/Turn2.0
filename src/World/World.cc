#include "World.h"
#include "Unit.h"
#include "Coord.h"
#include "WorldBlocks/WorldBlock.h"
#include "WorldBlocks/Grass.h"
#include <vector>

void World::generate(){
  chart.resize( size.getY(), vector<WorldBlock*>(size.getX()) );
	int x = 0, y = size.getY();

	vector<vector<WorldBlock*> >::iterator row;
	vector<WorldBlock*>::iterator col;

	WorldBlock* currentBlock;


  for(row = chart.end(); row > chart.begin() ; row--){
    for(col = row->begin(); col< row->end(); col++){
			x++;

			*col = new Grass;
			currentBlock = *col;

			currentBlock->location.setX(x);
			currentBlock->location.setY(y);
		}//end Collumn
		y--;
		x=0;
	}//end Row
}



void World::display(){
	vector<vector<WorldBlock*> >::iterator row;
	vector<WorldBlock*>::iterator col;
	WorldBlock* temp;

	for(row = chart.end(); row > chart.begin() ; row--){
    for(col = row->begin(); col< row->end(); col++){
			temp = *col;
			temp->display();
			cout<<' ';
		}
		cout<<endl;
	}
}

WorldBlock World::getWorldBlock(Coord blockLocation){

	vector<vector <WorldBlock*> >::iterator row = chart.begin() + blockLocation.getY();
  vector<WorldBlock*> ::iterator col = row->begin() + blockLocation.getX()-1;

	WorldBlock* block = *col;

	return *block;
}