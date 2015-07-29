//file shelfHash.h
//@version lab4
//@author Duong H Chau

/////////////////////////////////////////////////////////////////////////////////////
// Action Class
// A class that contains a description of an action for specific Patrons and allows
// retrieving the information stored
//	Containing Action in its own class allows code changes within the class to not
//	affect changes in other classes as long as contracts are set properly
//
// Features:
//      -- 
//      -- 
// Assumptions:
//      -- 
//      -- 
/////////////////////////////////////////////////////////////////////////////////////
#ifndef SHELFHASH
#define SHELFHASH
#include "Hash.h"
#include "nodedata.h"
#include "publication.h"
#include "publicationdb.h"

using namespace std;
class ShelfHash : public Hash {
	static const int MaxIndex = 26;  //MAX # of index in a hashtable
public:
	ShelfHash();                        //constructor
	virtual ~ShelfHash();               //destructor
	virtual int hashFunction(const NodeData*) const; //overwrite hasFunction
	virtual bool insert(NodeData*);                  //overwrite insert
	virtual bool retrieve(const NodeData&, NodeData*&)const;//overwrite retrieve
	void display()const;                           //display the entire hashtable
private:
	PublicationDB binTree[MaxIndex];             //array of PublicationDB
};

#endif
