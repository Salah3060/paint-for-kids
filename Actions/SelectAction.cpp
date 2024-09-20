#include "SelectAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"



SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	ClickedFigure = NULL;

}


void SelectAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("  Select a Figure   ");

	pIn->GetPointClicked(p.x, p.y);

}



void SelectAction::Execute(bool b)
{
	if (b)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	ClickedFigure = pManager->GetFigure(p.x, p.y);

	CFigure* oldSelected_Figure = pManager->GetSelected_Figure();
	if (oldSelected_Figure == nullptr && ClickedFigure != nullptr)
	{
		ClickedFigure->SetSelected(true);
		ClickedFigure->PrintInfo(pOut);
		pManager->setSelectedFigure(ClickedFigure);
	}

	// case two if selected figure is seclected before make it unselected and return NUL

	else if (oldSelected_Figure == ClickedFigure && ClickedFigure != nullptr)
	{
		ClickedFigure->SetSelected(false);
		pManager->setSelectedFigure(nullptr);

	}

	//  case 3 if the seleced figure isn't the selected before

	else if (ClickedFigure != nullptr)
	{
		oldSelected_Figure->SetSelected(false);
		ClickedFigure->SetSelected(true);
		ClickedFigure->PrintInfo(pOut);
		pManager->setSelectedFigure(ClickedFigure);
	}
}


