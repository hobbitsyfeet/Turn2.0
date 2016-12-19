#ifndef ITEM_H
#define	ITEM_H

class Item{
public:
	string getName();
	void getWorth();

	void setName(String);

	virtual void use() = 0;

private:
	string name;
	double worth;
};

#endif //ITEM_H