#include "WorldBlocks/DeepWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

DeepWater::DeepWater(){
	Colours effect;
	format = effect.blue();
	type = '~';
	collision = true;
}