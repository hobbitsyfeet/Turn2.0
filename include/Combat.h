#ifndef COMBAT_H
#define COMBAT_H

#include "./Unit.h"

class Combat{
public:
	void targetUnit(Unit*);
	void getInfo(Unit*);

	virtual void attack();
private:
	Unit* self;
	Unit* target;
};


#endif //COMBAT_H