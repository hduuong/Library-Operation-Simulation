/////////////////////////////////////////////////////////////////////////////////////
// Action Factory Class
//	A Hash table holds action objects
//  used to give back a correct type of action
// Features:
//      -- create a new action with a given token
//		-- unique hash function
// Assumptions:
//      -- Unable to instantiate the ActionFactory class directly.
/////////////////////////////////////////////////////////////////////////////////////
#ifndef ACTIONFACTORY
#define ACTIONFACTORY

#include <string>
#include <iostream>
#include "action.h"
#include "checkin.h"
#include "checkout.h"
#include "displayHistory.h"
using namespace std;

class ActionFactory{
	static const int MaxIndex = 26;
public:
	ActionFactory();
	~ActionFactory();
	Action* create(char);
private:
	int hasFunction(char);
	Action* actionArray[MaxIndex];
};
#endif;