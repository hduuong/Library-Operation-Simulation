//file BinTree.cpp
//@author Duong H Chau
//@version CSC 343 lab2

#include "bintree.h"

const int ARRAYSIZE = 100;
//---------------------------- Default Constructor -------------------------
// makes an empty tree
// sets the root to NULL
BinTree::BinTree(){
	root = NULL;
}

//---------------------------- Destructor -------------------------
// delete the tree
// this calls a helper method to delete the nodes recursively
BinTree::~BinTree(){
	makeEmpty();
}
//---------------------------- IsEmpty -------------------------
// finds out if the tree is empty or not
// @return true if tree is empty, false if not
bool BinTree::isEmpty() const{
	return root == NULL;
}

//---------------------------- MakeEmpty -------------------------
// this makes the tree empty by deleting all the nodes
// this calls a recursive helper method to complete the task
void BinTree::makeEmpty(){
	deleteTree(root);
	root = NULL;
}
//---------------------------- DeleteTree -------------------------
// helper method that delete all nodes in a tree
// recursive method
// @param node a node of a tree
void BinTree::deleteTree(Node*& node){
	if(node == NULL) {
		delete node;
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node->data;
	delete node;
}

//---------------------------- operator<< -------------------------
// this dispays the tree in inorder order
// @param output the output object
// @param tree the refference to the tree needs to be printout;
// @return the inorder presentation of the tree
ostream& operator<<(ostream& output, const BinTree& tree){
	tree.printTree(output,tree.root);
	output << endl;
	return output;
}
//---------------------------- PrintTree -------------------------
// displays out-put in inorder order
// recursive method
// @param output the refference to the output object
// @node the node of the tree
void BinTree::printTree(ostream&  output, Node* node) const{
	if(node == NULL) return;
	printTree(output, node->left);
	output << *node->data << " ";
	printTree(output, node->right);
}

//---------------------------- operator== -------------------------
// checks the equality of 2 trees
// @param tree the second tree need to compare with
// @return true if equals, false if not
bool BinTree::operator==(const BinTree & tree) const {
	return equality(root, tree.root);
}

//---------------------------- operator!= -------------------------
// checks the inequality of 2 trees
// @param tree the second tree need to compare with
// @return true if not equals, false if is
bool BinTree::operator!=(const BinTree & tree) const {
	return !equality(root, tree.root);
}

//---------------------------- Equality -------------------------
// helper method to check equality of 2 trees
// recursive method
// @param rootNode the node from the root tree
// @param node the node from the second tree
bool BinTree::equality(const Node* rootNode, const Node* node) const{
	if(rootNode == NULL && node == NULL) return true;
	if(rootNode == NULL && node != NULL) return false;
	if(rootNode != NULL && node == NULL) return false;
	if(*rootNode->data != *node->data) return false;
	if(!equality(rootNode->left, node->left)) return false;
	if(!equality(rootNode->right, node->right)) return false;

	return true;
}
//---------------------------- Retrieve -------------------------
// this finds the nodes that hold the data in parameter
// and assign that to the pointer in parameter
// @param data the data need to be found in the tree
// @param pointer a pointer to the refference of the data in the tree
// @return true if found, false if not
bool BinTree::retrieve(const Publication& data, Publication*& pointer)const{
	if(retrieveHelper(data, root, pointer)) return true;
	else {
		pointer = NULL;
		return false;
	}
}
//---------------------------- RetrieveHelper -------------------------
// the actual method that does the work in Retrieve's description
// recursive method
// @param data the data need to be found in the tree
// @param rootNode a node from the tree
// @param pointer a pointer to the refference of the data in the tree
// @return true if found, false if not
bool BinTree::retrieveHelper(const Publication& data, const Node* rootNode, Publication*& pointer)const{
	if(rootNode == NULL) {
		return false;
	}

	if(*rootNode->data == data){
		pointer = rootNode->data;
		return true;
	}else{
		return (retrieveHelper(data, rootNode->left, pointer) 
			|| retrieveHelper(data, rootNode->right, pointer));
	}
}

//---------------------------- Insert -------------------------
// inserts the node to the tree in appropriate order
// new node to be inserted is a leaf of a tree
// @param dataptr the data needs to be inserted
// @return true when successfully insert, false otherwise
bool BinTree::insert(Publication* dataptr){
	if (isEmpty()) {
		Node* ptr = new Node;
		if (ptr == NULL) return false;            // out of memory
		ptr->data = dataptr;
		ptr->left = ptr->right = NULL;
		root = ptr;
	}
	else {
		Node* current = root;                           // walking pointer
		bool inserted = false;                          // whether inserted yet
     // if item is less than current item, insert in left subtree,
     // otherwise insert in right subtree
		while (!inserted) {
			if (*dataptr < *current->data) {
				if (current->left == NULL) {              // insert left
					Node* ptr = new Node;
					if (ptr == NULL) return false;            // out of memory
					ptr->data = dataptr;
					ptr->left = ptr->right = NULL;
					current->left = ptr;
					inserted = true;
				} else
					current = current->left;               // one step left
			} else if (*dataptr > *current->data) {
				if (current->right == NULL) {             // insert right
					Node* ptr = new Node;
					if (ptr == NULL) return false;            // out of memory
					ptr->data = dataptr;
					ptr->left = ptr->right = NULL;
					current->right = ptr;
					current = current->right;
					inserted = true;
				} else
					current = current->right;              // one step right
			} else {                                       // already have this item
				return false;                             
			}
		}
	}
	return true;
}


