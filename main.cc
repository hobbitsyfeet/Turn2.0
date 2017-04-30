#include "WorldBlock.h"
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

	TestColours();
	TestUI();
	TestBlock();
	TestInventory();
	TestMap();
	return 0;
}


void TestColours(){
	cout<<red()<<"RED\n";
	cout<<yellow()<<"YELLOW\n";
	cout<<green()<<"GREEN\n";
	cout<<blue()<<"BLUE\n";
	cout<<magenta()<<"MAGENTA\n";
	cout<<cyan()<<"CYAN\n";
	cout<<white()<<"WHITE\n";
	cout<<gray()<<"GRAY\n";
	cout<<darkGray()<<"DARKGRAY\n";
	cout<<black()<<"BLACK\n";

	cout<<lightRed()<<"LIGHTRED\n";
	cout<<lightBlue()<<"LIGHTBLUE\n";
	cout<<lightGreen()<<"LIGHTGREEN\n";
	cout<<lightCyan()<<"LIGHTCYAN\n";

	cout<<white();


	cout<<redbg()<<"REDBG";
	cout<<defaults()<<endl;
	cout<<greenbg()<<"GREENBG";
	cout<<defaults()<<endl;
	cout<<bluebg()<<"BLUEBG";
	cout<<defaults()<<endl;
	cout<<magentabg()<<"MAGENTABG";
	cout<<defaults()<<endl;
	cout<<cyanbg()<<"CYANBG";
	cout<<defaults()<<endl;
	cout<<black()<<whitebg()<<"WHITEBG";

	cout<<defaults()<<endl;
}

void TestUI(){
	cout<<endl;
	cout<<statBar(3,10,0)<<endl;
	cout<<statBar(5,10,0)<<endl;
	cout<<statBar(10,10,0)<<endl;
	cout<<statBar(3,10,1)<<endl;
	cout<<statBar(5,10,1)<<endl;
	cout<<statBar(10,10,1)<<endl;
	cout<<statBar(3,10,2)<<endl;
	cout<<statBar(5,10,2)<<endl;
	cout<<statBar(10,10,2)<<endl;
	cout<<statBar(3,10,3)<<endl;
	cout<<statBar(5,10,3)<<endl;
	cout<<statBar(10,10,3)<<endl;
	cout<<endl;


	for(int i = 0; i <= 10; i++ ){
		cout<<statBar(i,10,0)<<100*i/10<<"%";
		cout<<endl;
	}

	for(int i = 0; i <= 100; i++ ){
		cout<<statBar(i,100,2)<<i<<"%";
		cout<<endl;
	}

	cout<<statBar(5,10,3,"small")<<endl;
	cout<<statBar(5,10,3,"medium")<<endl;
	cout<<statBar(5,10,3, "large")<<endl;
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
