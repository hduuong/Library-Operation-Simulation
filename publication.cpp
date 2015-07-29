//file publication.cpp
//@version lab4
//@author Duong H Chau

#include "publication.h"
Publication::Publication(){
	year = 0;
	thisBookTitle = "";
	thisBookAuthor = "";
	thisBookType = ' ';
	quantity = MAX_QUANTITY;
}
Publication::~Publication(){

}
int Publication::getYear()const{
	return year;
}
char Publication::getType()const{
	return thisBookType;
}
string Publication::getTitle()const{
	return thisBookTitle;
}
string Publication::getAuthor()const{
	return thisBookAuthor;
}

int Publication::getMonth()const{
	return 0;
}

ostream& operator<<(ostream& output, const Publication& book){
	book.print(output);
	return output;
}

bool Publication::checkout(){
	if(quantity != 0){
		quantity--;
		return true;
	}else{
		cout << "OUT OF STOCK" << endl;
		return false;
	}
}

bool Publication::returnbook(){
	if(quantity < MAX_QUANTITY){
		quantity++;
		return true;
	}else{
		cout << "MAX CAPACITY REACHED" << endl;
		return false;
	}
}

