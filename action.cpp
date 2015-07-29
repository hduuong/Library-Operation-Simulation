//file action.cpp
//@version lab4
//@author Duong H Chau

#include "action.h"

Action::~Action(){
	bookPtr = NULL;
}

Action::Action(){
	theAction = ' ';
	patronID = 0;
	bookType = ' ';
	bookAuthor = "";
	bookTitle = "";
	bookMonth = 0;
	bookYear = 0;
}
Action::Action(char act, int id){
	theAction = act;
	patronID = id;
	bookType = ' ';
	bookAuthor = "";
	bookTitle = "";
	bookMonth = 0;
	bookYear = 0;
}
Action::Action(char act, int id, char type, string author, string title){
	theAction = act;
	patronID = id;
	bookType = type;
	bookAuthor = author;
	bookTitle = title;
	bookMonth = 0;
	bookYear = 0;
}

Action::Action(char act, int id, char type, int year, int month, string title){
	theAction = act;
	patronID = id;
	bookType = type;
	bookAuthor = "";
	bookTitle = title;
	bookMonth = month;
	bookYear = year;
}
//---------------------------------------------------
//getType
//get the type of the book
//@return type of the book
char Action::getType()const{
	return bookType;
}
//---------------------------------------------------
//getID
//get the ID of the patron
//@return ID of the patron
int Action::getID()const{
	return patronID;
}
//---------------------------------------------------
//getAction
//get the action it will perform
//@return char value of an action
char Action::getAction()const{
	return theAction;
}
//---------------------------------------------------
//getYear
//get the year of the book
//@return year of the book
int Action::getYear()const{
	return bookYear;
}
//---------------------------------------------------
//getMonth
//get the month of the book
//@return month of the book
int Action::getMonth()const{
	return bookMonth;
}
//---------------------------------------------------
//getTitle
//get the title of the book
//@return title of the book
string Action::getTitle()const{
	return bookTitle;
}
//---------------------------------------------------
//getAuthor
//get the author of the book
//@return author of the book
string Action::getAuthor()const{
	return bookAuthor;
}
//---------------------------------------------------
//operator<<
//show the output of an action object
//@param output output object
//@action reference to the action object
//@return output object with data
ostream& operator<<(ostream& output, const Action& action){
	action.print(output);
	return output;
}

//---------------------------------------------------
//print
//print the action object
//@param outout outout object
//@return output object with set data
void Action::print(ostream& output)const{
	if(theAction == 'C'){
		output << "CheckOut  ";
		bookPtr->printForHistory();
	}else if(theAction == 'R'){
		output << "Return    ";
		bookPtr->printForHistory();
	}else{
	}
}
//---------------------------------------------------
//linkToPublication
//conncect the bookPtr to a book in the shelf
//@param book reference to a Publication
void Action::linkToPublication(Publication& book){
	bookPtr = &book;
}
