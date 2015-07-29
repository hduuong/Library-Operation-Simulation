//file checkout.cpp
//@version lab4
//@author Duong H chau

#include "displayHistory.h"
//---------------------------------------------------
//constructor
//call the super class constructor
//set the type to H
DisplayHistory::DisplayHistory() : Action(){
	theAction = 'H';
}
//---------------------------------------------------
//detructor
DisplayHistory::~DisplayHistory(){}
//---------------------------------------------------
//makeNew
//create a new displayHist object and return it
//@return a new displayHist object
Action* DisplayHistory::makeNew()const{
	return new DisplayHistory();
}
//---------------------------------------------------
//setData
//set data of the action using the infile
//@param infile the input file
void DisplayHistory::setData(ifstream& infile){
	infile >> patronID;
}
