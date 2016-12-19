#ifndef WORLDBLOCK_H
#define WORLDBLOCK_H

class WorldBlock{
public:
	void saveWorldBlock();
	void loadWorldBlock();

	void display();

	bool getCollision();
private:
	char type;
	string format;
	bool collision;
};

#endif //WORLDBLOCK_H