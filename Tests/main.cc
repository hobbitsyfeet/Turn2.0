#include "WorldBlocks/Grass.h"
#include "WorldBlocks/WorldBlock.h"
#include "WorldBlocks/ShallowWater.h"
#include "WorldBlocks/DeepWater.h"
#include "World.h"
#include "Colours.h"
#include "UI.h"
#include "Unit.h"
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

	UI test;
	cout<<endl;
	cout<<test.statBar(3,10,0)<<endl;
	cout<<test.statBar(5,10,0)<<endl;
	cout<<test.statBar(10,10,0)<<endl;
	cout<<test.statBar(3,10,1)<<endl;
	cout<<test.statBar(5,10,1)<<endl;
	cout<<test.statBar(10,10,1)<<endl;
	cout<<test.statBar(3,10,2)<<endl;
	cout<<test.statBar(5,10,2)<<endl;
	cout<<test.statBar(10,10,2)<<endl;
	cout<<test.statBar(3,10,3)<<endl;
	cout<<test.statBar(5,10,3)<<endl;
	cout<<test.statBar(10,10,3)<<endl;
	cout<<endl;


	for(int i = 0; i <= 10; i++ ){
		cout<<test.statBar(i,10,0)<<100*i/10<<"%";
		cout<<endl;
	}

	for(int i = 0; i <= 100; i++ ){
		cout<<test.statBar(i,100,2)<<i<<"%";
		cout<<endl;
	}

	cout<<test.statBar(5,10,3,"small")<<endl;
	cout<<test.statBar(5,10,3,"medium")<<endl;
	cout<<test.statBar(5,10,3, "large")<<endl;

	Unit testUnit;
	World map;
	map.size.setX(20);
	map.size.setY(30);
	map.generate();
	map.display();

	Coord testPlayerCoord;
	testPlayerCoord.setX(14);
	testPlayerCoord.setY(17);

	WorldBlock* testBlock = map.getWorldBlock(testPlayerCoord);

	cout<<testBlock->location.getX()<<",";
	cout<<testBlock->location.getY();

	cout<<endl;

	map.getWorldBlock(testPlayerCoord)->setUnit(testUnit);

	map.display();

	//map.getWorldBlock(testPlayerCoord)->getUnit()->display();

	return 0;
}
