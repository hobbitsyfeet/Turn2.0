#include "Coord.h"
#include <iostream>


int Coord::getX() const{
	return this->y;
}

int Coord::getY() const{
	return this->x;
}

void Coord::setX(int set){
	this->x = set;
}

void Coord::setY(int set){
	this->y = set;
}

void Coord::display(){
	std::cout<<x<<','<<y;
}

Coord& Coord::operator = (const Coord* operand){
	this->x = operand->getX();
	this->y = operand->getY();
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