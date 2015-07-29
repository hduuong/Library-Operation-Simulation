//file Hash.h
//@version lab 4
//@author Duong H Chau

//---------------------------------------------------------------------------
/*  Hash class: a super class for all specific Hash table
	FeatureS:
		forces children classes to overwrite
			HashFunction - its own unique hashFuntion
			insert  - inserts an object
			retrieve - get back an Object
*/
//---------------------------------------------------------------------------
#ifndef HASH
#define HASH
#include "nodedata.h"

using namespace std;

class Hash {
public:
	Hash();                                        //constructor
	~Hash();                                       //destructor
	virtual int hashFunction(const NodeData*) const = 0;  //pure virtual hash function
	virtual bool insert(NodeData*) = 0;             //pure virtual insert
	virtual bool retrieve(const NodeData&, NodeData*&)const = 0; //pure virtual retrieve
private:

};

#endif;
