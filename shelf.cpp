//file shelf.cpp
//@version lab4
//@author Duong H Chau

#include "shelf.h"
//---------------------------------------------------
//constructor
Shelf::Shelf(){}
//---------------------------------------------------
//destructor
Shelf::~Shelf(){}
//---------------------------------------------------
//retrieve
//retrieve a publication if exist and link it to the holder
//@param book the reference to the publication that need to be retrieved
//@param holder this will holder the actual publication, NULL if not found
//@return true if successful, false if not
bool Shelf::retrieve(const Publication& book, Publication*& holder)const{
	NodeData* ptr;
	bool found = hashOb.retrieve(book,ptr);
	holder = static_cast<Publication*>(ptr);
	return found;
}
//---------------------------------------------------
//insert
//insert a publication to the array
//this uses the hasFunction to find index
//@param book the publication object
//@return true if inserted, false it not
bool Shelf::insert(Publication* book){
	return hashOb.insert(book);
}
//----------------------------------------------------
//display
//call display on the hashShelf
void Shelf::display()const{
	hashOb.display();
}
