   //file librarian.cpp
//@version lab4
//@author Duong H Chau

#include "librarian.h"
//---------------------------------------------------
//constructor
Librarian::Librarian(){
}
//---------------------------------------------------
//detructor
//set the pointers to patronlist and self to NULL
Librarian::~Librarian(){
	patronRecord = NULL;
	PubSource = NULL;
}
//---------------------------------------------------
//buildActions
//build the actions using the infile
//this uses the factory to make a correct new action
//then set its data afterward
//@param infile the input file
void Librarian::buildActions(ifstream& infile){
	char act;
	Action* action;
	while(!infile.eof()){
		infile >> act;
		action = factory.create(act);
		if(action == NULL){
			string garbage;
			getline(infile,garbage);
			continue;
		}
		action->setData(infile);
		librarianTasks.insert(action);
	}
}
//---------------------------------------------------
//connectShelf
//connect the shelf pointer to the actual shelf
void Librarian::connectShelf(Shelf& shelf){
	PubSource = &shelf;
}
//---------------------------------------------------
//connectPatron
//connect the patronlist pointer to the action list
void Librarian::connectPatron(PatronHash& list){
	patronRecord = &list;
}
//---------------------------------------------------
//doAllTheAction
//do exactly that the name says
//execute all the commands/actions that is in the actionQueue
void Librarian::doAllTheAction(){
	Action* action;                            //pointer to action
	NodeData* patron;                          //pointer to patron
	Publication* book;                         //pointer to publication
	int year,month,ID;
	char booktype;
	string author,title;

	while(!librarianTasks.isEmpty()){
		action = librarianTasks.getAction();       //get one action from the actionQueue
		year = action->getYear();                  //get the year of the book
		month = action->getMonth();                //get the month of the book
		ID = action->getID();                      //get the ID of the patron
		booktype = action->getType();              //get the type of the book
		author = action->getAuthor();              //get the author of the book
		title = action->getTitle();                //get the title of the book

		Patron aStudent(action->getID());          //make a patron for retrieve method
		if(!patronRecord->retrieve(aStudent,patron)){//get the patron from patronHash
			cout << " INVALID PATRON'S ID FOUND"<<endl;
			delete action;
			continue;                              //error in data patron ID - SKIP
		}
		if (action->getAction() == 'H'){
			static_cast<Patron*>(patron)->getHistory();
			delete action;
			action = NULL;
			continue;
		}
		//////////////////////////////////////////////////////////////////////////////
		//retrieve the right book from the shelf
		if(booktype == 'Y'){
			Children children(booktype,author,title,year);
			PubSource->retrieve(children,book);
		}else if(booktype == 'P'){
			Periodical periodical(booktype,title,year,month);
			PubSource->retrieve(periodical,book);
		}else if(booktype == 'F'){
			Fiction fiction(booktype,author,title,year);
			PubSource->retrieve(fiction,book);
		} else {
			cout << "INVALID BOOK TYPE FOUND" << endl;
			delete action;
			continue;                              //error in data SKIP this action;
		}
		if (book == NULL){                         //book not found
			cout << "BOOK IS NOT IN SHELF" << endl;
			delete action;
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////
		//perform the correct action
		if (action->getAction() == 'C'){
			if(book->checkout()){                  //only perform when able to checkout a book
				static_cast<Patron*>(patron)->addToCheckedOut(book);
				static_cast<Patron*>(patron)->addToHistory(action);
				action->linkToPublication(*book);
				action = NULL;
			}else{
				delete action;
				action = NULL;
			}
		} else if (action->getAction() == 'R'){   
			//only perform when able to retrieve the book
			if(static_cast<Patron*>(patron)->removeFromCheckedOut(*book)){ 
				book->returnbook();
				static_cast<Patron*>(patron)->addToHistory(action);
				action->linkToPublication(*book);
				action = NULL;
			}else{
				delete action;
				action = NULL;
			}
		} else {
			cout << "INVALID ACTION TYPE FOUND" << endl;
			delete action;
			action = NULL;
			continue;
		}
	}
}