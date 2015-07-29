//---------------------------------------------------------------------------
/*  Publication class:	Pure Virtual class that describes the information
						on a publication intended to be extended
Features:
	--Displays details on publication
	--Displays information with output<<
	-- allow users to compare to another publication with the equality operator
	-- allow users to compare to another publication with the less than operator
Assumptions:
	--Must implements operator< and operator==
*/
//---------------------------------------------------------------------------
#ifndef PUBLICATION
#define PUBLICATION

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include "nodedata.h"

using namespace std;

class Publication : public NodeData{

   friend ostream& operator<<(ostream &, const Publication &);

public:
	static const int AUTHOR_OUTPUT_WIDTH = 15;
	static const int TITLE_OUTPUT_WIDTH = 25;
	static const int YEAR_OUTPUT_WIDTH = 4;
	static const int MONTH_OUTPUT_WIDTH = 2;
	static const int MAX_QUANTITY = 5;
	Publication();          // default constructor, data is set to an empty string
	~Publication();         //destructor
	virtual void print(ostream&)const = 0;                   //pure virtual print method
 	virtual bool operator==(const Publication &) const = 0;  //pure virtual operator==
	virtual bool operator!=(const Publication &) const = 0;  //pure virtual operator!=
	virtual bool operator<(const Publication &) const = 0;   //pure virtual operator<
	virtual bool operator>(const Publication &) const = 0;   //pure virtual operator>
	virtual void printForHistory() const = 0;                //pure virtual printForhistory
	virtual Publication* makeNew() const = 0;                //pure virtual makeNew
	virtual void setData(ifstream&) = 0;               //pure virtual setData
	virtual int getYear()const;                  //get the publication year
	virtual char getType()const;                 //get the publication type
	virtual string getTitle()const;              //get the publication title
	virtual string getAuthor()const;             //get the publication author
	virtual int getMonth()const;                 //get the publication month
	virtual bool checkout();                     //checkout a book, minus a quantity
	virtual bool returnbook();                   //return a book, plus to quantity
    //Functions to set private variables

protected:

    string thisBookTitle;
	string thisBookAuthor; 
	int year;
	char thisBookType;
//  Edition thisEdition;
	int quantity;


};

#endif
