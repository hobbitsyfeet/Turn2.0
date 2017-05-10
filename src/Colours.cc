#include "Colours.h"


/*
*	COLOURS
*
*/
string red(){
	string colour = "\033[31m";
return colour;
}

string yellow(){
	string colour = "\033[33m";
	return colour;
}

string green(){
	string colour = "\033[32m";
return colour;
}

string blue(){
	string colour = "\033[34m";
return colour;
}

string magenta(){
	string colour = "\033[35m";
return colour;
}

string cyan(){
	string colour = "\033[36m";
return colour;
}

string white(){
	string colour = "\033[97m";
return colour;
}

string gray(){
	string colour = "\033[37m";
return colour;
}

string darkGray(){
	string colour = "\033[90m";
	return colour;
}

string black(){
	string colour = "\033[30m";
return colour;
}


/**
*LIGHT COLOURS
*
*/
string lightRed(){
	string colour = "\033[91m";
	return colour;
}

string lightGreen(){
	string colour = "\033[92m";
	return colour;
}

string lightYellow(){
	string colour = "\033[93m";
	return colour;
}

string lightBlue(){
	string colour = "\033[94m";
	return colour;
}

string lightMagenta(){
	string colour = "\033[95m";
	return colour;
}

string lightCyan(){
	string colour = "\033[96m";
	return colour;
}

/**
*BACKGROUND COLOURS
*
*/

string redbg(){
	string colour = "\033[41m";
	return colour;
}
string greenbg(){
	string colour = "\033[42m";
	return colour;
}
string bluebg(){
	string colour = "\033[44m";
	return colour;
}
string magentabg(){
	string colour = "\033[45m";
	return colour;
}
string cyanbg(){
	string colour = "\033[46m";
	return colour;
}
string whitebg(){
	string colour = "\033[47m";
	return colour;
}

string defaults(){
	string colour = "\033[0m";
	return colour;
}
string bold(){
	string colour = "\033[1m";
	return colour;
}

string underline(){
	string colour = "\033[4m";
	return colour;
}

string blink(){
	string colour = "\033[5m";
	return colour;
}

string inverse(){
	string colour = "\033[7m";
	return colour;
}

string conceal(){
	string colour = "\033[8m";
	return colour;
}
