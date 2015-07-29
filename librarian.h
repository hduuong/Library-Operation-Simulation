//---------------------------------------------------------------------------
/*  Librarian class:	Manager Type class that retrieves Action objects and
						determines the apprpriate actions to take
						to complete the parameters in the Action object

Features:
	--
Assumptions:
	--
*/
//---------------------------------------------------------------------------
#ifndef LIBRARIAN
#define LIBRARIAN

#include <string>
#include <iostream>
#include <queue>
#include "actionList.h"
#include "shelf.h"
#include "patronHash.h"
#include "publication.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#include "actionFactory.h"

using namespace std;

class Librarian {
public:
	Librarian();
	~Librarian();

	void doAllTheAction();
	void buildActions(ifstream&);
	void connectShelf(Shelf&);
	void connectPatron(PatronHash&);
private:
	PatronHash* patronRecord; 
	ActionList librarianTasks;
	Shelf* PubSource;
	ActionFactory factory;
};

#endif
