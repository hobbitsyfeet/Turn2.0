#include "ShallowWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

ShallowWater::ShallowWater(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "ShallowWater";
	format = effect.lightBlue();
	type = '~';
	collision = false;
}
