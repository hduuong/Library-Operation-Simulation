/////////////////////////////////////////////////////////////////////////////
// Fiction
//    Derives from Publication to conform to Publication data requirements
// Features:
//      -- Implements Operator<
//      -- Implements Operator==
// Assumptions:
//      -- Operator< checks author then title
/////////////////////////////////////////////////////////////////////////////
#ifndef FICTION
#define FICTION

#include <string>
#include <iostream>
#include "publication.h"

using namespace std;

// ----- DERIVED CLASS Publication -------------------------------------------

class Fiction : public Publication {

public:
	Fiction(char,string,string,int);                   //constructor
	Fiction();                                          //default constructor
	~Fiction();                                //destrucor
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
