//---------------------------------------------------------------------------
/*  Periodical class:	Contains information of periodicals such as
						Title and Date(Year, Month)

Features:
	--Displays information with the output operator<<
	--Implements comparison operator<
	--Implements 
Assumptions:
	--All child classes must implement the operator functions based on their
		own specifications
*/
//---------------------------------------------------------------------------
#ifndef PERIODICAL
#define PERIODICAL

#include <string>
#include <iostream>
#include "publication.h"

using namespace std;

// ----- DERIVED CLASS Apple -------------------------------------------------

class Periodical : public Publication {

public:
	Periodical(char,string,int,int);                     //constructor
	Periodical();                                        //default constructor
	~Periodical();                                       //destructor
	virtual void print(ostream&) const;                   //overwrite print method
	virtual bool operator!=(const Publication &) const ;  //overwrite operator=
	virtual bool operator==(const Publication &) const ;  //overwrite operator==
	virtual bool operator<(const Publication &) const ;   //overwrite operator<
	virtual bool operator>(const Publication &) const ;   //overwrite operator>
	virtual void printForHistory() const;                  //overwrite printForHistory
	virtual Publication* makeNew()const;                  //overwrite makeNew
	virtual void setData(ifstream&);                       //overwrite setData
	int getMonth() const;
	
 private:
	 int month;

};

#endif
