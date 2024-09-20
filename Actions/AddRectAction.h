#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include "..\Figures\CRectangle.h"
//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* DeletedFig;
	CRectangle* R;

public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
void addundofirst(Action* pAct);
	//Add rectangle to the ApplicationManager
	 void Execute(bool b) ;
     void undo();
	 void redo();

	
	
};

#endif