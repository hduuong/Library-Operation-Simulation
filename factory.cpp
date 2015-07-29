//file factory.cpp
//@version lab4
//@author Duong H Chau

#include "factory.h"
//---------------------------------------------------
//constructor
//set the initial values to the array
Factory::Factory(){
	for(int i = 0; i < MaxIndex; i++){
		bookArray[i] = NULL;
	}
	bookArray['P' - 'A'] = new Periodical();
	bookArray['F' - 'A'] = new Fiction();
	bookArray['Y' - 'A'] = new Children();
}
//---------------------------------------------------
//detructor
//delete all data in array and sets to NULL
Factory::~Factory(){
	for(int i = 0; i < MaxIndex; i++){
		delete bookArray[i];
		bookArray[i] = NULL;
	}
}
//---------------------------------------------------
//HashFunction
//unique hash function
//@param ch, a character
//@return an integer
int Factory::hasFunction(char ch){
	return ch - 'A';
}
//---------------------------------------------------
//create
//return a correct version of publication with a given token
//@param ch, a character
//@return correct version of publication
Publication* Factory::create(char ch){
	int idx = hasFunction(ch);
	if(idx < 0 || idx >= MaxIndex){
		cout << "INVALID BOOK TYPE" << endl;
		return NULL;
	}
	if(bookArray[idx] == NULL){
		cout << "INVALID BOOK TYPE" << endl;
		return NULL;
	}
	return bookArray[idx]->makeNew();
}