//file actionList.cpp
//@version lab4
//@author Duong H Chau

#include "actionList.h"
//---------------------------------------------------
//constructor
ActionList::ActionList(){
}
//---------------------------------------------------
//destructor
//pop out all the data from the actionQ
ActionList::~ActionList(){
	while(actionQ.size() != 0){
		actionQ.pop();
	}
}

//---------------------------------------------------
//insert
//insert an action to the list 
//@param act, pointer to an action
//@retrun true if inserted, false if not
bool ActionList::insert(Action* act){
	actionQ.push(act);
	return true;
}
//---------------------------------------------------
//getAction
//pop out first token in the Queue and return it
//@return a action object
Action* ActionList::getAction(){
	Action* ptr = actionQ.front();
	actionQ.pop();
	return ptr;
}
//---------------------------------------------------
//isEmpty
//check of the queue is empty
//@return true if it is empty, false if not
bool ActionList::isEmpty()const{
	return actionQ.size() == 0;
}
