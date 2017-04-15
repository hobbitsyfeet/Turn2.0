#include "Colours.h"


/*
*	COLOURS
*
*/
string Colours::red(){
	string colour = "\033[31m";
return colour;
}

string Colours::yellow(){
	string colour = "\033[33m";
	return colour;
}

string Colours::green(){
	string colour = "\033[32m";
return colour;
}

string Colours::blue(){
	string colour = "\033[34m";
return colour;
}

string Colours::magenta(){
	string colour = "\033[35m";
return colour;
}

string Colours::cyan(){
	string colour = "\033[36m";
return colour;
}

string Colours::white(){
	string colour = "\033[97m";
return colour;
}

string Colours::gray(){
	string colour = "\033[37m";
return colour;
}

string Colours::darkGray(){
	string colour = "\033[90m";
	return colour;
}

string Colours::black(){
	string colour = "\033[30m";
return colour;
}


/**
*LIGHT COLOURS
*
*/
string Colours::lightRed(){
	string colour = "\033[91m";
	return colour;
}

string Colours::lightGreen(){
	string colour = "\033[92m";
	return colour;
}

string Colours::lightYellow(){
	string colour = "\033[93m";
	return colour;
}

string Colours::lightBlue(){
	string colour = "\033[94m";
	return colour;
}

string Colours::lightMagenta(){
	string colour = "\033[95m";
	return colour;
}

string Colours::lightCyan(){
	string colour = "\033[96m";
	return colour;
}

/**
*BACKGROUND COLOURS
*
*/

string Colours::redbg(){
	string colour = "\033[41m";
	return colour;
}
string Colours::greenbg(){
	string colour = "\033[42m";
	return colour;
}
string Colours::bluebg(){
	string colour = "\033[44m";
	return colour;
}
string Colours::magentabg(){
	string colour = "\033[45m";
	return colour;
}
string Colours::cyanbg(){
	string colour = "\033[46m";
	return colour;
}
string Colours::whitebg(){
	string colour = "\033[47m";
	return colour;
}

string Colours::defaults(){
	string colour = "\033[0m";
	return colour;
}
string Colours::bold(){
	string colour = "\033[1m";
	return colour;
}

string Colours::underline(){
	string colour = "\033[4m";
	return colour;
}

string Colours::blink(){
	string colour = "\033[5m";
	return colour;
}

string Colours::inverse(){
	string colour = "\033[7m";
	return colour;
}

string Colours::conceal(){
	string colour = "\033[8m";
	return colour;
}
