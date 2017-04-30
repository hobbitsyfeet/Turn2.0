#include "UI.h"
#include "Colours.h"
#include <iostream>

/**
*	respective colours : RED,GREEN,BLUE,WHITE
*/
string statBar(int stat, int maxStat, int colour, string length){

	int size;
	if (length == "small"){
		size = 15;
	}
	else if(length == "medium"){
		size = 25;
	}
	else if(length == "large"){
		size = 35;
	}
	else{
		size = 25;
	}

	double percent = (size * stat / maxStat);
	int numHighlights = percent;
	bool endBar = false;
	string highlight;
	string lowlight;

	string bar;
	if(colour == 0){
		highlight = lightRed();
		lowlight = red();
	}
	else if (colour == 1){
		highlight = yellow();
		lowlight = green();
	}
	else if (colour == 2){
		highlight = cyan();
		lowlight = blue();
	}
	else if(colour == 3){
		highlight = gray();
		lowlight = darkGray();
	}

	for(int index = 0; index < size; index++){

		if( (numHighlights == 0 && endBar == false)){
			endBar=true;
			bar.append("|");
		}

		if(numHighlights != 0){
			bar.append(bold());
			bar.append(highlight);
			numHighlights --;
		}

		else{
			bar.append(lowlight);
		}
		bar.append("_");
		bar.append(defaults());
	}

	if(endBar == false)
	bar.append("|");

	return bar;
}

string statBar(int stat, int maxStat, int colour){
	return statBar(stat,maxStat,colour, "medium");
}