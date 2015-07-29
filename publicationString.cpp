//file publicationString.cpp
//@version lab4
//@author Duong H Chau

#include "publicationString.h"

PublicationString::PublicationString(){
	pString << "";
}

PublicationString::~PublicationString(){
}

void PublicationString::print()const{
	cout << pString.str();
}

void PublicationString::setString(string str){
	pString << str;
}

string PublicationString::getString()const{
	return pString.str();
}

