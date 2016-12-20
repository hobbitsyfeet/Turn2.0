#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

	#include <fstream>
	#include<iostream>

using namespace std;

class WorldBlock{
public:
	void saveWorldBlock( ofstream& );
 	void loadWorldBlock( ifstream& );

	void display();

	bool getCollision();

protected:
	int x,y;

	string format;
	string name;
	char type;
	bool collision;
private:
};

#endif //WORLDBLOCK_H