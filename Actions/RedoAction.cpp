#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "AddRectAction.h"
#include"AddcircleAction.h"
#include"AddTriangleAction.h"
#include"AddSquareAction.h"
#include"AddHexaAction.h"
#include"SelectAction.h"
#include "PrepareExport.h"
#include "PrepareImport.h"
#include "UndoAction.h"
#include "fstream"
#include "..\Figures/CCircle.h"
#include "RedoAction.h"


RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp) {}

void RedoAction::AddToActions(Action* Act)
{
}



void RedoAction::Execute(bool b)
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Action* pAct = pManager->GetLastRedo();


	if (pAct != NULL)
	{
		pOut->PrintMessage("Redo the last operation");
		pAct->redo();
		pManager->addToUndo(pAct);


	}
	else
	{
		pOut->PrintMessage("there is not enough operations to redo!!");//if there is enough operations to undo
	}
}

void RedoAction::ReadActionParameters()
{
	

}

