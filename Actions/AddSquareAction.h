#pragma once
#include "Action.h"
#include "..\DefS.h"
#include "..\Figures\CSquare.h"

class AddSquareAction : public Action
{
private:
	Point P1, P2;
	GfxInfo SquareGfxInfo;
	CFigure* DeletedFig;
	
	CSquare* s;
public :
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	 void Execute(bool b);
	 void addundofirst(Action* pAct);
	 void undo();
	void redo();
	Point  GetCenter();
	Point Getp2();
	


};

