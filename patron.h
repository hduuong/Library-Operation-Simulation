//---------------------------------------------------------------------------
/*  Patron class:	Contains information and functions to retrieve info
					on a Patron
					Information Stored
					-Patron ID
					-Information on Patron in container class
					-Information on a Patrons Library History
					-Current Checked out books
Features:
	-- a patron can keep its record of activity(checkin, checkout)
	-- a patron can keep track of the pubications that it checks out

Assumptions:
	-- ID and patron's info is correct, invalid data is checked and ignored at file reading
*/   
//---------------------------------------------------------------------------
#ifndef PATRON
#define PATRON

#include <string>
#include <iostream>
#include <vector>
#include "publication.h"
#include "action.h"
using namespace std;



class Patron : public NodeData{

   friend ostream & operator<<(ostream &, const Patron &);

public:
	static const int MaxChar = 10;      //Max # of char in display for names
	Patron(int);
	Patron(int,string,string);          //constructor
	~Patron();          
	
	//Functions to set and get Patron Details
	bool operator==(const Patron&)const; //overwrite operator==
    int getID()const;                      //get the patron's ID

    void addToHistory(Action*);        //add an action to history
    void getHistory();                 //print the history of actions

    void addToCheckedOut(Publication*);//add to checkout List
	bool removeFromCheckedOut(const Publication&); //remove from checkout list
    void getCheckedOut();             //display the checkout List

private:
    int ID ;
	string lastname;
	string firstname;
	vector<Action*> history;
	vector<Publication*> COutList;


};
#endif

