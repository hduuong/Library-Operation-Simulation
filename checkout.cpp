//file checkout.cpp
//@version lab4
//@author Duong H chau

#include "checkout.h"
//---------------------------------------------------
//constructor
//call the super class constructor
//set the type to C
CheckOut::CheckOut() : Action(){
	theAction = 'C';
}
//---------------------------------------------------
//detructor
CheckOut::~CheckOut(){}
//---------------------------------------------------
//makeNew
//create a new CheckOut object and return it
//@return a new CheckOut object
Action* CheckOut::makeNew()const{
	return new CheckOut();
}
//---------------------------------------------------
//setData
//set data of the action using the infile
//@param infile the input file
void CheckOut::setData(ifstream& infile){
	infile >> patronID >> bookType >> bookVersion;
	if(bookVersion != 'H'){
		string garbage;
		getline(infile,garbage);
		return;
	}
	if(bookType == 'P'){
		infile >> bookYear >> bookMonth;
		infile.get();
		getline(infile, bookTitle, ',');
	} else if(bookType == 'Y' ){
		infile.get(); 
		getline(infile,bookTitle,',');
		infile.get();
		getline(infile,bookAuthor,',');
	} else if (bookType == 'F'){
		infile.get(); 
		getline(infile,bookAuthor,',');
		infile.get();
		getline(infile,bookTitle,',');
	} else {
		string garbage;
		getline(infile,garbage);
		cout << " INVALID BOOK TYPE" << endl;
		return;
	}
}