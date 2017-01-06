#ifndef COORD_H
#define COORD_H

#include <iostream>

class Coord{
	public:
		Coord(int = 0,int = 0);
		int getX() const;
		int getY() const;

		void setX(int);
		void setY(int);
		void set(int, int);

		void display();

		Coord& operator = (const Coord*);
		bool operator != (const Coord*);
		bool operator == (const Coord*);

	private:
		int x;
		int y;
};

#endif //COORD_H