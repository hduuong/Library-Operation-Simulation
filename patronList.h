//---------------------------------------------------------------------------
/*  Shelf class:	Hashtable contains of the different kinds of PublicationDB
					classes.
Features:
    -- insert a book into sprcific database
	-- retrive an book from publication database in the list
Assumptions:
	-- for this project, theShelfInTheLibrary only holds 3 type of 
	   publication database
*/   
//---------------------------------------------------------------------------
#ifndef PATRONLIST	
#define PATRONLIST

#include "patron.h"
#include "patronHash.h"
#include <string>
#include <iostream>
using namespace std;



class PatronList {
public:
    PatronList();
    ~PatronList();
	void display() const;
	bool retrieve(const Patron &, Patron*&) const; // retrive a target book
	bool insert(Patron*);           // insert a book to correct DB

private:
	// holds different type of publications database
	PatronHash hashOb;
};

#endif

