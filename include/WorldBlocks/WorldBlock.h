#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

	#include <fstream>
	#include<iostream>

using namespace std;

class WorldBlock{
public:
	virtual	void saveWorldBlock( ofstream& );
	virtual void loadWorldBlock( ifstream& );

	void display();

	bool getCollision();

protected:
	string format;
	char type;
	bool collision;
private:
};

#endif //WORLDBLOCK_H