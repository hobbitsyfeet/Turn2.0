#include "WorldBlocks/Grass.h"
#include "Colours.h"
#include<iostream>
using namespace std;

Grass::Grass(){
	Colours effect;
	name= "Grass";
	format = effect.green();
	type = ',';
	collision = false;
}