// -----------------------------------------------------------------------------
/*  Library class:	Instance Class, contains the primary classes
					and method calls to read data and process data

  The Library class contains four data members, which are a container for user
 patrons(PatronList class), the library curator(Librarian class), the factory
 pattern/process(Processors class), and a storage system in which books can be
 stored(Shelf class).
 
Features:
	-- Has a librarian to deal with transactions
	-- Has a bookshelf to keep track of books
	-- Has a processor to call for actions when there are commands
	-- Has a list to keep track of the patrons
Assumptions:
	-- A library must have all of the members (librarian, shelf, processor, patronlist)
	-- even when they are empty
*/
// -----------------------------------------------------------------------------

#ifndef LIBRARY
#define LIBRARY

#include "librarian.h"
//#include "processor.h"


#include "shelf.h"
#include "periodical.h"
#include "children.h"
#include "fiction.h"
#include "factory.h"
#include "patronHash.h"
#include "patron.h"

#include <iostream>
#include <fstream>
#include <sstream>
class Library
{
public:
    Library();                   //constructor
    virtual ~Library();          //destructor

    void buildShelf(ifstream&);     //build the bookshelf
    void buildLibrarian(ifstream&); //build the librarian
    void buildPatrons(ifstream&);   //build the patron list
    void runLibrarian();            //execute the commands

	void displayShelf();            //display the bookshelf
	void displayPatrons();          //dislay the patron list
private:
	Librarian librarian;  //Librarian
	Shelf bookshelf;      //Shelf
	PatronHash plist;     //PatronHash
	Factory objFactory;   //Factory
};

#endif
