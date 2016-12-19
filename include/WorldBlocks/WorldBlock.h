#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

	#include <fstream>
	#include<iostream>

using namespace std;

class WorldBlock{
public:
	void saveWorldBlock( ofstream& );
	void loadWorldBlock( ifstream&);

	void display();

	bool getCollision();
protected:
	string format;
	char type;
	bool collision;
};

#endif //WORLDBLOCK_H