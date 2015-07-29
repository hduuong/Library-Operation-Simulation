//file childen.cpp
//@version lab4
//@author Duong H Chau

#include "children.h"

Children::Children(char type, string name, string title, int yearPub)
	: Publication(){
	year = yearPub;
	thisBookTitle = title;
	thisBookAuthor = name;
	thisBookType = type;
}
//---------------------------------------------------
//constructor
//calls constructor of super class
//set data to unique data members
Children::Children() : Publication(){
	thisBookType = 'Y';
}
//---------------------------------------------------
//detructor
Children::~Children(){
}
//---------------------------------------------------
//operator<
//overwrite the operator<
//@param book the book that compare to
//@return true if less than, false if grater
bool Children::operator<(const Publication& book)const{
	if(thisBookTitle < book.getTitle()) return true;
	else if(thisBookTitle == book.getTitle()){
		return thisBookAuthor < book.getAuthor();
	}else
		return false;
}
//---------------------------------------------------
//operator>
//overwrite the operator>
//@param book the book that compare to
//@return true if grater than, false if smaller
bool Children::operator>(const Publication& book)const{
	if(thisBookTitle > book.getTitle()) return true;
	else if(thisBookTitle == book.getTitle()){
		return thisBookAuthor > book.getAuthor();
	}else
		return false;
}
//---------------------------------------------------
//operator==
//overwrite the operator==
//@param book the book that compare to
//@return true if equals, false if not
bool Children::operator==(const Publication& book)const{
	return (thisBookAuthor == book.getAuthor()
		&& thisBookTitle == book.getTitle() && thisBookType == book.getType());
}
//---------------------------------------------------
//operator!=
//overwrite the operator!=
//@param book the book that compare to
//@return true if not equals, false if equals
bool Children::operator!=(const Publication& book)const{
	return !(*this==book);
}
//---------------------------------------------------
//print
//display the format of this type of publication
//@parem output the output object
void Children::print(ostream& output)const{
	output << " " << quantity << "    ";
	output << left << setw(AUTHOR_OUTPUT_WIDTH) << thisBookAuthor.substr(0,(AUTHOR_OUTPUT_WIDTH)) << "    "
	<< left << setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << "   "
	<<  year << endl;
}
//---------------------------------------------------
//printForHistory
//display the format of this type of publication for the history 
void Children::printForHistory() const{
	cout << left << setw(AUTHOR_OUTPUT_WIDTH) << thisBookAuthor.substr(0,(AUTHOR_OUTPUT_WIDTH)) << "    "
	<< left <<setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << "   "
	<<  year << endl;
}
//---------------------------------------------------
//makeNew
//make a new Children object and return it
//@return a new Children object
Publication* Children::makeNew()const{
	return new Children();
}
//---------------------------------------------------
//setData
//set data of the book using the file input
//@param infile the input file
void Children::setData(ifstream& infile){
	infile.get();
	getline(infile,thisBookAuthor,',');
	infile.get();
	getline(infile,thisBookTitle,',');
	infile >> year;
}