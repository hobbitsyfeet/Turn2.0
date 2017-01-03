#include "WorldBlocks/DeepWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

DeepWater::DeepWater(){
	Colours effect;
	OccupiedUnit = NULL;
	name = "DeepWater";
	format = effect.blue();
	type = '~';
	collision = true;
}