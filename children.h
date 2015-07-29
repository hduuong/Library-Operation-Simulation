//---------------------------------------------------------------------------
/*  Children class:	Contains information on Children objects derived
					from Publication. Will implement the Operators
					differently

Features:
	-- allow users to compare to another children book with the equality operator
	-- allow users to compare to another children book with the less than operator
Assumptions:
	-- Must implements operator< and operator==
*/
//---------------------------------------------------------------------------
#ifndef CHILDREN
#define CHILDREN

#include <string>
#include <iostream>
#include <iomanip>
#include "publication.h"


using namespace std;

// ----- DERIVED CLASS Publication -------------------------------------------

class Children : public Publication {

public:
	Children(char,string,string,int);                   //constructor
	Children();                                          //default constructor
	~Children();                                        //destrucor
	virtual void print(ostream&) const;                   //overwrite print method
	virtual bool operator!=(const Publication &) const;    //overwrite operator!=
	virtual bool operator==(const Publication &) const ;   //overwrite operator==
	virtual bool operator<(const Publication &) const ;    //overwrite operator<
	virtual bool operator>(const Publication &) const ;    //overwrite operator>
	virtual void printForHistory() const;                  //overwrite printForHistory
	virtual Publication* makeNew()const;                  //overwrite makeNew
	virtual void setData(ifstream&);                       //overwrite setData
private:

};
#endif
