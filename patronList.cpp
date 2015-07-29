//file patronList.cpp
//@version lab4
//@author Duong H Chau

#include "patronList.h"

PatronList::PatronList(){}

PatronList::~PatronList(){}

bool PatronList::retrieve(const Patron& book, Patron*& holder)const{
	NodeData* ptr;
	bool found = hashOb.retrieve(book,ptr);
	holder = static_cast<Patron*>(ptr);
	return found;
}

bool PatronList::insert(Patron* book){
	return hashOb.insert(book);
}

void PatronList::display()const{
	hashOb.display();
}