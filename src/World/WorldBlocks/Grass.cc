#include "WorldBlocks/Dirt.h"
#include "Colours.h"
#include<iostream>
using namespace std;

Dirt::Dirt(){
	Colours effect;
	//cout<<prefix.green()<<"test";
	format = effect.green();
	type = ',';
}