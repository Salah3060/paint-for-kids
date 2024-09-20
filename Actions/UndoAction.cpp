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

 UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp) {}
 

void UndoAction::Execute(bool b) {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	
	
	Action* pAct = pManager->GetLastUndo();


	if (pAct != NULL)
	{ pOut->PrintMessage("Undo the last operation");
		pAct->undo();
		pManager->addToRedo();

	}
	else
	{
		pOut->PrintMessage("there is not enough operations to undo!!");//if there is enough operations to undo
	}
}


void UndoAction::ReadActionParameters() {

	
	
}

void UndoAction::undo()
{
	
}

void UndoAction::redo()
{
}
