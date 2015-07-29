//---------------------------------------------------------------------------
/*  ActionList class:	Contains the Action objects in the order given
						and gives Action objects in the same order
Features:
	-- Has a queue to store and determine which command of action to execute first
Assumptions:
	-- Can be implemented in any Data Structure but queue makes sense
*/   
//---------------------------------------------------------------------------
#include "action.h"
#include <queue>
class ActionList
{
public:
	ActionList();
	~ActionList();
	//Functions to add and remove from ActionList
	bool insert(Action*);
	Action* getAction();     //get the action as popping from queue
	bool isEmpty()const;     //check if the queue is empty
private:
	queue<Action*> actionQ;

};
