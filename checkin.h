//file checkin.h
//@version lab4
//@author Duong H Chau

// -----------------------------------------------------------------------------
/*  CheckIn Function class: Takes an Action Object that contains information
 on checking in a Publication and performs
 the CheckIn Action
 Features:
   -- create a new Object CheckIn and return to the caller
   -- setData fill in the necessary data
 Assumptions:
    -- data from the list are all valid
    -- invalid data are checked and ignored while reading off file
    -- the list is empty by default */
// -----------------------------------------------------------------------------

#ifndef CHECKIN
#define CHECKIN

#include <string>
#include <iostream>
#include "action.h"
using namespace std;

class CheckIn : public Action{
public:
	CheckIn();
	~CheckIn();
	virtual Action* makeNew()const;        //overwrtie makeNew
	virtual void setData(ifstream&);  //overwrite setData
};

#endif;
