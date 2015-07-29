//file patronHash.cpp
//@version lab4
//@author Duong H Chau

#include "patronHash.h"
//---------------------------------------------------
//constructor
//set initual value to array
PatronHash::PatronHash(){
	for(int i = 0; i < MaxIndex; i++){
		patronList[i] = NULL;
	}
}
//---------------------------------------------------
//destructor
//delete everything in the array
PatronHash::~PatronHash(){
	for(int i = 0; i < MaxIndex; i++){
		delete patronList[i];
	}
}
//---------------------------------------------------
//hashFunction
//return a unique int using when passing in a patron object
//@param student a patron object
//@return a unique int
int PatronHash::hashFunction(const NodeData* student) const{
	return static_cast<const Patron*>(student)->getID();
}
//---------------------------------------------------
//insert
//insert a patron to the array
//this uses the hasFunction to find index
//@param student the patron object
//@return true if inserted, false it not
bool PatronHash::insert(NodeData* student){
	int idx = hashFunction(student);
	if(patronList[idx] != NULL) return false;

	patronList[idx] = (static_cast<Patron*>(student));
	return true;
}
//---------------------------------------------------
//retrieve
//retrieve a patron if exist and link it to the holder
//@param student the reference to the patron that need to be retrieved
//@param holder this will holder the actual patron, NULL if not found
//@return true if successful, false if not
bool PatronHash::retrieve(const NodeData& student, NodeData*& holder)const{
	int idx = hashFunction(&student);
	if(patronList[idx] == NULL){
		holder = NULL;
		return false;
	}
	bool found = false;
	if(*patronList[idx] == static_cast<const Patron&>(student)){
		holder = patronList[idx];
		found = true;
	}else{
		holder = NULL;
	}
	return found;
}
//---------------------------------------------------
//display
//display the entire list 
void PatronHash::display()const{
	cout << " ID    Last          First" << endl;
	for(int i = 0; i < MaxIndex; i++){
		if(patronList[i] != NULL){
			cout << *patronList[i];
		}
	}
	cout << endl;
}

