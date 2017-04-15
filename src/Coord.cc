#include "Coord.h"
#include <iostream>

Coord::Coord(int x, int y){
	this->x = x;
	this->y = y;
}

int Coord::getX() const{
	return this->x;
}

int Coord::getY() const{
	return this->y;
}

void Coord::setX(int set){
	this->x = set;
}

void Coord::setY(int set){
	this->y = set;
}

void Coord::set(int X,int Y){
	this->x = X;
	this->y = Y;
}

void Coord::display(){
	std::cout<<x<<','<<y;
}

Coord& Coord::operator = (const Coord* operand){
	this->x = operand->getX();
	this->y = operand->getY();
	return *this;
}

bool Coord::operator !=(const Coord* operand){
	bool checkX = this->x != operand->getX();
	bool checkY = this->y != operand->getY();

	if(checkX && checkY)
	return true;
	else
	return false;
}

bool Coord::operator ==(const Coord* operand){
	bool checkX = this->x == operand->getX();
	bool checkY = this->y == operand->getY();

	if(checkX && checkY)
	return true;
	else
	return false;
}
