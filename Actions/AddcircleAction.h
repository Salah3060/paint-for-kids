#pragma once
#include "Action.h"
#include "..\DefS.h"
#include "..\Figures\CCircle.h"
//Add circle Action class

class AddcircleAction : public Action
{
  private : 
    Point P1, P2;
    GfxInfo CircleGfxInfo;
	CCircle* c;
	CFigure* DeletedFig;
public:
	AddcircleAction(ApplicationManager* pApp);
	 void addundofirst(Action* pAct);
	//Reads Circle  parameters
	virtual void ReadActionParameters();
	//Add Circle to the ApplicationManager
 void Execute(bool b);
	 void undo();
	void redo();
	
};



