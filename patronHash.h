

//file patronHash
//@version lab4
//@author Duong H Chau
#ifndef PATRONHASH
#define PATRONHASH
#include "Hash.h"
#include "nodedata.h"
#include "patron.h"
using namespace std;

class PatronHash : public Hash{
	static const int MaxIndex = 10000;      //Max # of index in hashtable
public:
	PatronHash();                                   //constructor
	virtual ~PatronHash();                          //destructor
	virtual int hashFunction(const NodeData*) const;//overwrite hashFunction
	virtual bool insert(NodeData*);                 //insert data to list
	bool retrieve(const NodeData&, NodeData*&)const;//retrieve data from list
	void display()const;                            //display the list
private:
	Patron* patronList[MaxIndex];                   //list of patron*
};

#endif

