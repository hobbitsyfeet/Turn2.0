#include "WorldBlocks/Grass.h"
#include "Colours.h"
#include<iostream>
using namespace std;

Grass::Grass(){
	Colours effect;
	//cout<<prefix.green()<<"test";
	format = effect.green();
	type = ',';
}