//file shelfHash.cpp
//@version lab4
//@author Duong H Chau

#include "shelfHash.h"
//---------------------------------------------------
//constructor
ShelfHash::ShelfHash(){
}
//---------------------------------------------------
//destructor
ShelfHash::~ShelfHash(){
}
//---------------------------------------------------
//hashFunction
//return a unique int using when passing in a patron object
//@param student a patron object
//@return a unique int
int ShelfHash::hashFunction(const NodeData* book) const{
	return static_cast<const Publication*>(book)->getType() - 'A';
}
//---------------------------------------------------
//insert
//insert a publication to the array
//this uses the hasFunction to find index
//@param book the publication object
//@return true if inserted, false it not
bool ShelfHash::insert(NodeData* book){
	int idx = hashFunction(book);
	if(binTree[idx].getString().compare("") == 0){
		if(static_cast<const Publication*>(book)->getType() == 'F'){
			binTree[idx].setString("FICTION:\nAVAIL AUTHOR                TITLE                     YEAR\n ");
		} else if(static_cast<const Publication*>(book)->getType() == 'Y'){
			binTree[idx].setString("CHILDREN:\nAVAIL AUTHOR               TITLE                      YEAR\n ");
		} else if(static_cast<const Publication*>(book)->getType() == 'P'){
			binTree[idx].setString("PERIODICAL:\nAVAIL  YEAR MO TITLE\n ");
		}else{
		}
	}
	return binTree[idx].insert(book);
}

//---------------------------------------------------
//retrieve
//retrieve a publication if exist and link it to the holder
//@param book the reference to the publication that need to be retrieved
//@param holder this will holder the actual publication, NULL if not found
//@return true if successful, false if not
bool ShelfHash::retrieve(const NodeData& book, NodeData*& holder)const{
	int idx = hashFunction(&book);
	return binTree[idx].retrieve(book,holder);
	
}
//---------------------------------------------------
//display
void ShelfHash::display()const{
	for(int i = 0; i < MaxIndex; i++){
		binTree[i].display();
	}
}

