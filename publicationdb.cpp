//file publicationDb.cpp
//@version lab4
//@author Duong H Chau

#include "publicationdb.h"
//---------------------------------------------------
//constructor
PublicationDB::PublicationDB(){
}
//---------------------------------------------------
//destructor
PublicationDB::~PublicationDB(){
	tree.makeEmpty();
}
//---------------------------------------------------
//display
//display the string and the tree
void PublicationDB::display()const{
	str.print();
	cout << tree;
}
//---------------------------- Retrieve -------------------------
// this finds the nodes that hold the data in parameter
// and assign that to the pointer in parameter
// @param data the data need to be found in the tree
// @param pointer a pointer to the refference of the data in the tree
// @return true if found, false if not
bool PublicationDB::retrieve(const NodeData& book, NodeData*& holder)const{
	bool found = false;
	Publication* ptr;
	found = tree.retrieve(static_cast<const Publication&>(book),ptr);
	holder = ptr;
	return found;
}
//---------------------------- Insert -------------------------
// inserts the node to the tree in appropriate order
// new node to be inserted is a leaf of a tree
// @param dataptr the data needs to be inserted
// @return true when successfully insert, false otherwise
bool PublicationDB::insert(NodeData* book){
	return tree.insert(static_cast<Publication*>(book));
}
//---------------------------------------------------
//getString
//get the string object
//@return the string of the string object
string PublicationDB::getString()const{
	return str.getString();
}
//---------------------------------------------------
//setString
//set data to the string object
void PublicationDB::setString(string ss){
	str.setString(ss);
}

