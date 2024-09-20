#include "clearAll.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "Action.h"

clearAll::clearAll(ApplicationManager* pApp): Action(pApp) 
{
}


void clearAll::ReadActionParameters()
{
}

void clearAll::Execute(bool b)
{

	pManager->ClearAll();

	pManager->clearUndoRedoFuncs();

	Output* pOut = pManager->GetOutput();

	CFigure::ResetID();
	

	pOut->PrintMessage("Everything is cleared");

}

void clearAll::undo()
{
}

void clearAll::redo()
{
}
