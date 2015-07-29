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
#ifndef SHELF	
#define SHELF

#include "shelfHash.h"
#include "publicationdb.h"
#include "publication.h"
#include <string>
#include <iostream>
using namespace std;



class Shelf {
public:
    Shelf();
    ~Shelf();
	void display() const;
	bool retrieve(const Publication &, Publication*&) const; // retrive a target book
	bool insert(Publication*);           // insert a book to correct DB

private:
	// holds different type of publications database
	ShelfHash hashOb;
};

#endif

