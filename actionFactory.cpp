//file actionFactory.cpp
//@version lab4
//@author Duong H Chau

#include "actionFactory.h"
//---------------------------------------------------
//constructor
//set the initial values of the array
ActionFactory::ActionFactory(){
	for(int i = 0; i < MaxIndex; i++){
		actionArray[i] = NULL;
	}
	actionArray['C' - 'A'] = new CheckOut();
	actionArray['R' - 'A'] = new CheckIn();
	actionArray['H' - 'A'] = new DisplayHistory();
}

//---------------------------------------------------
//detructor
//delete all data in array and sets to NULL
ActionFactory::~ActionFactory(){
	for(int i = 0; i < MaxIndex; i++){
		delete actionArray[i];
		actionArray[i] = NULL;
	}
}

//---------------------------------------------------
//HashFunction
//unique hash function
//@param ch, a character
//@return an integer
int ActionFactory::hasFunction(char ch){
	return ch - 'A';
}
//---------------------------------------------------
//create
//return a correct version of action with a given token
//@param ch, a character
//@return correct version of action
Action* ActionFactory::create(char ch){
	int idx = hasFunction(ch);
	if(idx < 0 || idx >= MaxIndex){
		cout << "INVALID COMMAND" << endl;
		return NULL;
	}
	if(actionArray[idx] == NULL){
		cout << "INVALID COMMAND" << endl;
		return NULL;
	}
	return actionArray[idx]->makeNew();
}
