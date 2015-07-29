//file patron.cpp
//@version lab4
//@author Duong H Chau

#include "patron.h"
//---------------------------------------------------
//constructor that takes in an integer
//used to retrieve the actual patron
//@param id the patron's ID
Patron::Patron(int id){
	ID = id;
	lastname = "";
	firstname = "";
}
//---------------------------------------------------
//constructor
//@param id the patron's ID
//@param lname patron's first name
//@param fname patron's last name
Patron::Patron(int id,string lname,string fname){
	ID = id;
	lastname = lname;
	firstname = fname;
}
//---------------------------------------------------
//destructor
//set all the pointer in checkout list to NULL
//delete all the action objects in the history
Patron::~Patron(){
	for(vector<Publication*>::iterator it = COutList.begin(); it != COutList.end(); ++it){
		*it = NULL;
	}
	for(vector<Action*>::iterator it = history.begin(); it != history.end(); ++it){
		delete *it;
		*it = NULL;
	}
}
//---------------------------------------------------
//operator==
//overwrite operator==
//only check the ID becuse it is Unique, no other should equals
//@param student the patron to compare
//@return true if equals, false if not
bool Patron::operator==(const Patron& student)const{
	return (ID == student.ID);
}
//---------------------------------------------------
//getID
//get the patron's ID
//@return the patron's ID
int Patron::getID()const{
	return ID;
}
//---------------------------------------------------
//addToCheckedOut
//add the the checkoutList with pointer to publication
//@book pointer to publication
void Patron::addToCheckedOut(Publication* book){
	COutList.push_back(book);
}
//---------------------------------------------------
//getCheckedOut
//display all books in the checked out List
void Patron::getCheckedOut(){
	//iterate the vector
	for(vector<Publication*>::iterator it = COutList.begin(); it != COutList.end(); ++it){
		(*it)->printForHistory();
	}
}
//---------------------------------------------------
//operator<<
//overwrite operator<<
//display the patron with a specific format
//@param output the output object
//@param student the reference to a patron
//@return the output object
ostream& operator<<(ostream& output, const Patron& student){
	output.setf(ios::left, ios::adjustfield);
	if(student.ID / 10 == 0){
		output << "000" << student.ID;
		output << "    " << setw(student.MaxChar) << student.lastname;
		output << "    " << setw(student.MaxChar) << student.firstname << endl;
		return output;
	}
	if (student.ID / 100 == 0){
		output << "00" << student.ID;
		output << "    " << setw(student.MaxChar) << student.lastname;
		output << "    " << setw(student.MaxChar) << student.firstname << endl;
		return output;
	}
	if (student.ID / 1000 == 0){
		output << "0" << student.ID;
		output << "    " << setw(student.MaxChar) << student.lastname;
		output << "    " << setw(student.MaxChar) << student.firstname << endl;
		return output;
	}
	output << student.ID;
	output << "    " << setw(student.MaxChar) << student.lastname;
	output << "    " << setw(student.MaxChar) << student.firstname << endl;
	return output;
}
//---------------------------------------------------
//addToHistory
//add to the history the object of action
//@param action the pointer to the object
void Patron::addToHistory(Action* action){
	history.push_back(action);
}
//---------------------------------------------------
//getHistory
//display the history of transactions
void Patron::getHistory(){
	cout << endl << "*** Patron ID = " << ID << "  " << lastname << " " << firstname << endl;
	for(vector<Action*>::iterator it = history.begin(); it != history.end(); ++it){
		cout << **it;
	}
}
//---------------------------------------------------
//removeFromCheckOut
//remove a book from the checked out list
//@param book, reference of the book needs to be removed
//@return true if able to remove, false if not
bool Patron::removeFromCheckedOut(const Publication& book){
	bool found = false;
	for(vector<Publication*>::iterator it = COutList.begin(); it != COutList.end(); ++it){
		if(*it == NULL) break;
		if(**it == book){
			found = true;
			*it = NULL;
		}
	}
	if(!found){
		cout << "DID NOT CHECK OUT THIS BOOK" << endl;
	}
	return found;
}

