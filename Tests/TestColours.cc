#include "../include/Colours.h"
#include <iostream>
using namespace std;

int main(){
Colours format;

cout<<format.red()<<"red\n";
cout<<format.yellow()<<"yellow\n";
cout<<format.green()<<"green\n";
cout<<format.blue()<<"blue\n";
cout<<format.magenta()<<"magenta\n";
cout<<format.cyan()<<"cyan\n";
cout<<format.white()<<"white\n";
cout<<format.gray()<<"gray\n";
cout<<format.darkGray()<<"darkGray\n";
cout<<format.black()<<"black\n";

cout<<format.lightRed()<<"lightRed\n";
cout<<format.lightBlue()<<"lightBlue\n";
cout<<format.lightGreen()<<"lightGreen\n";
cout<<format.lightCyan()<<"lightCyan\n";

cout<<format.white();

cout<<format.redbg()<<"redbg\n";
cout<<format.greenbg()<<"greenbg\n";
cout<<format.bluebg()<<"bluebg\n";
cout<<format.magentabg()<<"magentabg\n";
cout<<format.cyanbg()<<"cyanbg\n";
cout<<format.black()<<format.whitebg()<<"whitebg\n";

return 0;
};