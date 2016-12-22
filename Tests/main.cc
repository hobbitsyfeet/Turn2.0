#include "WorldBlocks/Grass.h"
#include "WorldBlocks/WorldBlock.h"
#include "WorldBlocks/ShallowWater.h"
#include "WorldBlocks/DeepWater.h"
#include "World.h"
#include "Colours.h"
int main(){
Colours format;
WorldBlock* block;

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

	block = new Grass;
	cout<<"grass:";
	block->display();
	cout<<endl;
	//delete block;

	block = new ShallowWater;
	cout<<format.white()<<"ShallowWater:";
	block->display();
	cout<<endl;
	//delete block;

	block = new DeepWater;
	cout<<format.white()<<"DeepWater:";
	block->display();
	//delete block;

	Unit test;
	cout<<endl;
	cout<<test.statBar(3,10,"Green")<<endl;
	cout<<test.statBar(5,10,"Green")<<endl;
	cout<<test.statBar(10,10,"Green")<<endl;
	cout<<test.statBar(3,10,"Blue")<<endl;
	cout<<test.statBar(5,10,"Blue")<<endl;
	cout<<test.statBar(10,10,"Blue")<<endl;
	cout<<test.statBar(3,10,"Red")<<endl;
	cout<<test.statBar(5,10,"Red")<<endl;
	cout<<test.statBar(10,10,"Red")<<endl;
	cout<<test.statBar(3,10,"Gray")<<endl;
	cout<<test.statBar(5,10,"Gray")<<endl;
	cout<<test.statBar(10,10,"Gray")<<endl;
	cout<<endl;


	for(int i = 0; i <= 10; i++ ){
		cout<<test.statBar(i,10,"Green")<<100*i/10<<"%";
		cout<<endl;
	}

	for(int i = 0; i <= 100; i++ ){
		cout<<test.statBar(i,100,"Red")<<i<<"%";
		cout<<endl;
	}

	World map;
	map.size.setX(20);
	map.size.setY(30);
	map.generate();
	map.display();
	return 0;
}
