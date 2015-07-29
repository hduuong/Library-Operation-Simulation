//file periodical.cpp
//@version lab4
//@author Duong H Chau

#include "periodical.h"
Periodical::Periodical(char type, string title, int yearPub, int monthPub){
	month = monthPub;
	year = yearPub;
	thisBookTitle = title;
	thisBookAuthor = "";
	thisBookType = type;
}
//---------------------------------------------------
//constructor
//calls constructor of super class
//set data to unique data members
Periodical::Periodical() : Publication(){
	thisBookType = 'P';
	month = 0;
	quantity = 1;
}
//---------------------------------------------------
//detructor
Periodical::~Periodical(){
}
//---------------------------------------------------
//getMonth
//get the month of the book
//@return month of the book
int Periodical::getMonth()const{
	return month;
}
//---------------------------------------------------
//operator<
//overwrite the operator<
//@param book the book that compare to
//@return true if less than, false if grater
bool Periodical::operator<(const Publication& book)const{
	if(year < book.getYear()) return true;                 //year is smaller
	else if(year == book.getYear()){                       //year is equal -> check month
		if(month < book.getMonth()) return true;           //month is smaller
		else if(month == book.getMonth()){                 //month is equal -> check title
			return thisBookTitle < book.getTitle();
		}else
			return false;                                  //month is greater
	}else                                                  //year is greater
		return false;
}
//---------------------------------------------------
//operator>
//overwrite the operator>
//@param book the book that compare to
//@return true if grater than, false if smaller
bool Periodical::operator>(const Publication& book)const{
	if(year > book.getYear()) return true;                 //year is greater
	else if(year == book.getYear()){                       //year is equal -> check month
		if(month > book.getMonth()) return true;           //month is greater
		else if(month == book.getMonth()){                 //month is equal -> check title
			return thisBookTitle > book.getTitle();
		}else
			return false;                                  //month is smaller
	}else                                                  //year is smaller
		return false;
}
//---------------------------------------------------
//operator==
//overwrite the operator==
//@param book the book that compare to
//@return true if equals, false if not
bool Periodical::operator==(const Publication& book)const{
	return (year == book.getYear() && month == book.getMonth()
		&& thisBookTitle == book.getTitle() && thisBookType == book.getType());
}
//---------------------------------------------------
//operator!=
//overwrite the operator!=
//@param book the book that compare to
//@return true if not equals, false if equals
bool Periodical::operator!=(const Publication& book)const{
	return !(*this==book);
}
//---------------------------------------------------
//print
//display the format of this type of publication
//@parem output the output object
void Periodical::print(ostream& output)const{
	output << " " << quantity << "    "
		<< year << " " << right <<setw(2)<< month << " "
		<< left << setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << endl;
} 
//---------------------------------------------------
//printForHistory
//display the format of this type of publication for the history 
void Periodical::printForHistory() const{
	cout << year << " " << right <<setw(2)<< month << " "
		<< left << setw(TITLE_OUTPUT_WIDTH) << thisBookTitle.substr(0,TITLE_OUTPUT_WIDTH) << endl;
}
//---------------------------------------------------
//makeNew
//make a new Periodial object and return it
//@return a new Periodical object
Publication* Periodical::makeNew()const{
	return new Periodical();
}

//---------------------------------------------------
//setData
//set data of the book using the file input
//@param infile the input file
void Periodical::setData(ifstream& infile){
	infile.get();
	getline(infile, thisBookTitle, ',');
	infile >> month >> year;
}