//file factory.h
//@version lab4
//@author Duong H Chau

#include "publication.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#ifndef FACTORY
#define FACTORY

class Factory{
	static const int MaxIndex = 26;
public:
	Factory();
	~Factory();
	Publication* create(char);
private:
	int hasFunction(char);
	Publication* bookArray[MaxIndex];
};
#endif;
