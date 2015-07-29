//file fiction.cpp
//@version lab4
//@author Duong H Chau

#include "fiction.h"
Fiction::Fiction(char type, string name, string title, int yearPub)
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
Fiction::Fiction() : Publication(){
	thisBookType = 'F';
}
//---------------------------------------------------
//detructor
Fiction::~Fiction(){
}
//---------------------------------------------------
//operator<
//overwrite the operator<
//@param book the book that compare to
//@return true if less than, false if grater
bool Fiction::operator<(const Publication& book)const{
	if(thisBookAuthor < book.getAuthor()) return true;
	else if(thisBookAuthor == book.getAuthor()){
		return thisBookTitle < book.getTitle();
	}else
		return false;
}
//---------------------------------------------------
//operator>
//overwrite the operator>
//@param book the book that compare to
//@return true if grater than, false if smaller
bool Fiction::operator>(const Publication& book)const{
	if(thisBookAuthor > book.getAuthor()) return true;
	else if(thisBookAuthor == book.getAuthor()){
		return thisBookTitle > book.getTitle();
	}else
		return false;
}
//---------------------------------------------------
//operator==
//overwrite the operator==
//@param book the book that compare to
//@return true if equals, false if not
bool Fiction::operator==(const Publication& book)const{
	return (thisBookAuthor == book.getAuthor()
		&& thisBookTitle == book.getTitle() && thisBookType == book.getType());
}
//---------------------------------------------------
//operator!=
//overwrite the operator!=
//@param book the book that compare to
//@return true if not equals, false if equals
bool Fiction::operator!=(const Publication& book)const{
	return !(*this==book);
}
//---------------------------------------------------
//print
//display the format of this type of publication
//@parem output the output object
void Fiction::print(ostream& output)const{
	output << " " << quantity << "    ";
	output << left << setw(AUTHOR_OUTPUT_WIDTH) << thisBookAuthor.substr(0,(AUTHOR_OUTPUT_WIDTH)) << "    "
	<< left <<setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << "   "
	<<  year << endl;
}
//---------------------------------------------------
//printForHistory
//display the format of this type of publication for the history 
void Fiction::printForHistory() const{
	cout << left << setw(AUTHOR_OUTPUT_WIDTH) << thisBookAuthor.substr(0,(AUTHOR_OUTPUT_WIDTH)) << "    "
	<< left <<setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << "   "
	<<  year << endl;
}
//---------------------------------------------------
//makeNew
//make a new Fiction object and return it
//@return a new Fiction object
Publication* Fiction::makeNew()const{
	return new Fiction();
}
//---------------------------------------------------
//setData
//set data of the book using the file input
//@param infile the input file
void Fiction::setData(ifstream& infile){
	infile.get();
	getline(infile,thisBookAuthor,',');
	infile.get();
	getline(infile,thisBookTitle,',');
	infile >> year;
}
