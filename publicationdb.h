// file publicationDB.h
// @version lab4
// @author Duong H Chau


#ifndef PUBLICATIONDB_H
#define PUBLICATIONDB_H
#include <string>
#include <iostream>
#include <fstream>
#include "publication.h"
#include "publicationString.h"
#include "bintree.h"

using namespace std;

class PublicationDB{ 
	
public:
	PublicationDB();           //constructor
	~PublicationDB();          //destructor
	bool insert(NodeData*);                           //insert
	bool retrieve(const NodeData&, NodeData*&)const;  //retrieve
	void display()const;      //display a publicationdb
	string getString()const;  //get the string
	void setString(string);   //set data to string
private:
	BinTree tree;             //tree of binary tree
	PublicationString str;    //publicationString
};

#endif

