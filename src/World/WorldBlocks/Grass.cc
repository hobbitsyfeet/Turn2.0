#include "WorldBlocks/Grass.h"
#include "Colours.h"
#include<iostream>
using namespace std;

Grass::Grass(){
	Colours effect;
	format = effect.green();
	type = ',';
	collision = false;
}