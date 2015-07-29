//file publicationString.h
//@version lab4
//@author Duong H CHau

#ifndef PUBLICATIONSTRING
#define PUBLICATIONSTRING

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class PublicationString{
public:
	PublicationString();      //constructor
	PublicationString(char);  //constructor
	~PublicationString();     //destructor
	string getString()const;  //get the string
	void setString(string);   //set data to the string
	void print()const;        //display the string
private:
	ostringstream pString;    //stringstream object
};
#endif
