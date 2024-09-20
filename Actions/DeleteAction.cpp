#include "DeleteAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
	deletedFigure = nullptr;
}
void DeleteAction::ReadActionParameters()
{

}
void DeleteAction::Execute(bool b)
{
	Output* pOut = pManager->GetOutput();

	    
	if (pManager->GetSelected_Figure() == NULL)
		pOut->PrintMessage("NO SELECTED ");
	else
	{
		deletedFigure = pManager->GetSelected_Figure();
		pManager->DeleteFunction();
	}


}

void DeleteAction::undo()
{
	pManager->AddFigure(deletedFigure);

}

void DeleteAction::redo()
{
	deletedFigure = pManager->DeleteFigure();
}

void DeleteAction::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}
