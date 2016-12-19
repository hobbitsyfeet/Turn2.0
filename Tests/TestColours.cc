#include "../include/Colours.h"
#include <iostream>
using namespace std;

int main(){
Colours format;

cout<<format.red()<<"RED\n";
cout<<format.yellow()<<"YELLOW\n";
cout<<format.green()<<"GREEN\n";
cout<<format.blue()<<"BLUE\n";
cout<<format.magenta()<<"MAGENTA\n";
cout<<format.cyan()<<"CYAN\n";
cout<<format.white()<<"WHITE\n";
cout<<format.gray()<<"GRAY\n";
cout<<format.darkGray()<<"DARKGRAY\n";
cout<<format.black()<<"BLACK\n";

cout<<format.lightRed()<<"LIGHTRED\n";
cout<<format.lightBlue()<<"LIGHTBLUE\n";
cout<<format.lightGreen()<<"LIGHTGREEN\n";
cout<<format.lightCyan()<<"LIGHTCYAN\n";

cout<<format.white();

cout<<format.redbg()<<"REDBG\n";
cout<<format.greenbg()<<"GREENBG\n";
cout<<format.bluebg()<<"BLUEBG\n";
cout<<format.magentabg()<<"MAGENTABG\n";
cout<<format.cyanbg()<<"CYANBG\n";
cout<<format.black()<<format.whitebg()<<"WHITEBG\n";


return 0;
};