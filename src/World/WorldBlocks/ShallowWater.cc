#include "WorldBlocks/shallowWater.h"
#include "Colours.h"
#include<iostream>
using namespace std;

shallowWater::shallowWater(){
	Colours effect;
	format = effect.lightBlue();
	type = '~';
	collision = true;
}