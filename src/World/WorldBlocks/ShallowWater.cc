#include "WorldBlocks/ShallowWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

ShallowWater::ShallowWater(){
	Colours effect;
	name = "ShallowWater";
	format = effect.lightBlue();
	type = '~';
	collision = true;
}