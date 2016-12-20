#include "WorldBlocks/DeepWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

DeepWater::DeepWater(){
	Colours effect;
	name = "DeepWater";
	format = effect.blue();
	type = '~';
	collision = true;
}