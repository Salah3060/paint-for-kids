#ifndef ACTION_H
#define ACTION_H
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager* pManager;	//Actions needs AppMngr to do their job
	//	static int ActCount ;		            //Actual number of Actions
	Action* ActList[5];       //actual array of actions
	//Action* TempActList[200];   temporary array of actions


public:
	Action() {};

	Action(ActionType act) {};


	virtual void addundofirst(Action* pAct);
	virtual void undo();
	 virtual void redo();
	 int CheckAction() { return 0; };



	void RemoveLastAction() {};

	Action(ApplicationManager* pApp) {
		for (int i = 0; i < 5; i++)
			ActList[i] = NULL;
		pManager = pApp;
	};	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() {};

	//Execute action (code depends on action type)
	virtual void Execute(bool b=1) {};

};

#endif 
