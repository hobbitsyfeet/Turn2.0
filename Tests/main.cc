#include "WorldBlocks/Grass.h"
#include "WorldBlocks/WorldBlock.h"
#include "WorldBlocks/ShallowWater.h"
#include "WorldBlocks/DeepWater.h"
#include "Colours.h"
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


cout<<format.redbg()<<"REDBG";
cout<<format.defaults()<<endl;
cout<<format.greenbg()<<"GREENBG";
cout<<format.defaults()<<endl;
cout<<format.bluebg()<<"BLUEBG";
cout<<format.defaults()<<endl;
cout<<format.magentabg()<<"MAGENTABG";
cout<<format.defaults()<<endl;
cout<<format.cyanbg()<<"CYANBG";
cout<<format.defaults()<<endl;
cout<<format.black()<<format.whitebg()<<"WHITEBG";

cout<<format.defaults()<<endl;

	WorldBlock* block = new Grass;
	cout<<"grass:";
	block->display();
	cout<<endl;
	delete block;

	block = new ShallowWater;
	cout<<format.white()<<"ShallowWater:";
	block->display();
	cout<<endl;
	delete block;

	block = new DeepWater;
	cout<<format.white()<<"DeepWater:";
	block->display();
	delete block;
	return 0;
}
