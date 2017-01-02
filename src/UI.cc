#include "UI.h"
#include "Colours.h"
#include <iostream>

/**
*	respective colours : RED,GREEN,BLUE,WHITE
*/
string UI::statBar(int stat, int maxStat, int colour, string length){
	int size;
	if (length == "small"){
		size = 10;
	}
	else if(length == "medium"){
		size = 25;
	}
	else if(length == "large"){
		size = 45;
	}
	else{
		size = 25;
	}
	double percent = (size * stat / maxStat);
	int numHighlights = percent;
	bool endBar = false;
	Colours format;
	string highlight;
	string lowlight;

	string bar;
	if(colour == 0){
		highlight = format.lightRed();
		lowlight = format.red();
	}
	else if (colour == 1){
		highlight = format.yellow();
		lowlight = format.green();
	}
	else if (colour == 2){
		highlight = format.cyan();
		lowlight = format.blue();
	}
	else if(colour == 3){
		highlight = format.gray();
		lowlight = format.darkGray();
	}

	for(int index = 0; index < size; index++){

		if( (numHighlights == 0 && endBar == false)){
			endBar=true;
			bar.append("|");
		}

		if(numHighlights != 0){
			bar.append(format.bold());
			bar.append(highlight);
			numHighlights --;
		}

		else{
			bar.append(lowlight);
		}
		bar.append("_");
		bar.append(format.defaults());
	}

	if(endBar == false)
	bar.append("|");

	return bar;
}

string UI::statBar(int stat, int maxStat, int colour){
	return statBar(stat,maxStat,colour, "medium");
}