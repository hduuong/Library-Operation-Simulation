//file library.cpp
//@version lab4
//@author Duong H Chau
#include "library.h"
using namespace std;
//---------------------------------------------------
//constructor
Library::Library(){}
//---------------------------------------------------
//detructor
Library::~Library(){}
//---------------------------------------------------
//buildShelf
//build the bookshelf using the infile
//this calls that fatory to make a correct type of book
//then set data to that book
void Library::buildShelf(ifstream& infile){
	string line;
	char type;
	Publication* book;
	while(!infile.eof()){
		infile >> type;
		book = objFactory.create(type);
		if(book == NULL){
			string garbage;
			getline(infile,garbage);
			continue;
		}
		book->setData(infile);
		bookshelf.insert(book);
	}
}
//---------------------------------------------------
//displayShelf
//display the entire bookshelf with all the books in it
void Library::displayShelf(){
	bookshelf.display();
}
//---------------------------------------------------
//buildPatron
//build the patron list using the infile
void Library::buildPatrons(ifstream& infile){
	int id;
	string last;
	string first;
	Patron* student;
	while(!infile.eof()){
		infile >> id >> last >> first;
		student = new Patron(id,last,first);
		plist.insert(student);
	}
}
//---------------------------------------------------
//displayPatron
//display the entire list of patrons
void Library::displayPatrons(){
	plist.display();
}
//---------------------------------------------------
//buildLibrarian
//pass downt the infile to the librarian to build the list of actions
//connect the bookshelf to the librarian
//connect the patron list to the librarian
void Library::buildLibrarian(ifstream& infile){
	librarian.buildActions(infile);
	librarian.connectShelf(bookshelf);
	librarian.connectPatron(plist);
}

//---------------------------------------------------
//runLibrarian
//calls do it all method in librarian
void Library::runLibrarian(){
	librarian.doAllTheAction();
}

