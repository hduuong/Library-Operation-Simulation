//file checkout.cpp
//@version lab4
//@author Duong H chau

#include "checkin.h"
//---------------------------------------------------
//constructor
//call the super class constructor
//set the type to R
CheckIn::CheckIn() : Action(){
	theAction = 'R';
}
//---------------------------------------------------
//detructor
CheckIn::~CheckIn(){}

//---------------------------------------------------
//makeNew
//create a new CheckIn object and return it
//@return a new CheckIn object
Action* CheckIn::makeNew()const{
	return new CheckIn();
}
//---------------------------------------------------
//setData
//set data of the action using the infile
//@param infile the input file
void CheckIn::setData(ifstream& infile){
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
