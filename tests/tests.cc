#include "WorldBlock.h"
#include "Grass.h"
#include "ShallowWater.h"
#include "DeepWater.h"
#include "World.h"
#include "Colours.h"
#include "UI.h"
#include "Unit.h"
#include "Item.h"

void TestColours();
void TestUI();
void TestBlock();
void TestInventory();
void TestMap();
int main(){

	//TestColours();
	//TestUI();
	TestBlock();
	TestInventory();
	//TestMap();
	return 0;
}


void TestColours(){
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
}

void TestUI(){
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
}

void TestBlock(){
	WorldBlock* block;
	block = new Grass;
	cout<<"grass:";
	//block->display();
	cout<<endl;
	delete block;

	block = new ShallowWater;
	cout<<"ShallowWater:";
	block->display();
	cout<<endl;
	delete block;

	block = new DeepWater;
	cout<<"DeepWater:";
	block->display();
	delete block;
}

void TestMap(){
	Unit testUnit;
	World map;
	Coord index1(2,5);

	map.size.setX(5);
	map.size.setY(10);
	map.generate();
	map.display();

	WorldBlock* testBlock = map.getWorldBlock(index1);
	map.getWorldBlock(index1)->setUnit(testUnit);
	map.display();
}


void TestInventory(){
	Unit testUnit;
	Item* selectItem;

	Item item1;
	Item item2("Apple", 2);
	Item item3("Dog",5);
	Item item4("Rabbit",5);
	Item item5("Toy",5);

	selectItem = &item2;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item1;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item3;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item2;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item4;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item5;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item2;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item2;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;

	selectItem = &item2;
	testUnit.inventory.addItem(selectItem);
	testUnit.inventory.display();
	cout<<endl;
}
