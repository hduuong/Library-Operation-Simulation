/////////////////////////////////////////////////////////////////////////////////////
// Action Class
// A class that contains a description of an action for specific Patrons and allows
// retrieving the information stored
//	Containing Action in its own class allows code changes within the class to not
//	affect changes in other classes as long as contracts are set properly
// The description includes:
//       a character that determine the actions:
//               -- C for checkout
//               -- R for return
//               -- H for displaying the history
//       an integer refers to the patron's ID
//       title of the book
//       author of the book
//       date of the book
//       a character determines what type of book it is:
//               -- Y for children
//               -- F for fiction
//               -- P for periodicals
//               -- Support for future additions
// Features:
//      -- allow users to retrieve the action
//      -- allow users to retrieve the id
//      -- allow users to retrieve the book title
//      -- allow users to retrieve the book author
//      -- allow users to retrieve the book type
//      -- allow users to retrieve the book date
// Assumptions:
//      -- all the data is correctly formated
//      -- invalid data is checked and ignored while reading the file
/////////////////////////////////////////////////////////////////////////////////////
#ifndef ACTION
#define ACTION

#include <string>
#include <iostream>
#include "publication.h"
using namespace std;

class Action {
	friend ostream& operator<<(ostream &, const Action &);
public:
	Action(char act, int id, char type, int year, int month, string title);
	Action(char act, int id, char type, string author, string title);
	Action(char act, int id);
	Action();
     ~Action();

	 //Functions to set and access data
	 virtual Action* makeNew() const = 0;                //pure virtual makeNew
	 virtual void setData(ifstream&) = 0;               //pure virtual setData
	 virtual char getType()const;      //get the Type of book
	 virtual int getID()const;         //get the ID of the patron
	 virtual char getAction()const;    //get the Action it performs
	 virtual string getTitle()const;   //get the Title of book
	 virtual string getAuthor()const;  //get the Author of book
	 virtual int getYear()const;       //get the Year of book
	 virtual int getMonth()const;      //get the Month of book
	 virtual void print(ostream&)const;//print the action
	 virtual void linkToPublication(Publication&); //link pointer to the associated book
protected:
	 char theAction;
	 int patronID;
	 char bookType;
	 char bookVersion;
	 string bookTitle;
	 string bookAuthor;
	 int bookYear;
	 int bookMonth;
	 Publication* bookPtr; 
};

#endif

