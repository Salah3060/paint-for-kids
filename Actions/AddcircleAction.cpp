#include "AddcircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddcircleAction::AddcircleAction(ApplicationManager* pApp) :Action(pApp)
{


}
void AddcircleAction::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}
void AddcircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circe: Click at centre point ");


	pIn->GetPointClicked(P1.x, P1.y);
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight) || (P1.x < 10) || (P1.x) >= UI.width - 20)
	{
		pOut->PrintMessage("wrong click another center");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click another point ");
	pIn->GetPointClicked(P2.x, P2.y);
	int r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	while (!((P1.y - r) > UI.ToolBarHeight + 5 && (P1.y + r) < UI.height - UI.StatusBarHeight) || (P1.x - r) < 5 || (P1.x + r) >= UI.width - 15)
	{
		pOut->PrintMessage("click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
		r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));

	}

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}
void AddcircleAction::Execute(bool b)
{
	if (b)
		//This action needs to read some parameters first
		ReadActionParameters();

	//Create a circle with the parameters read from the user

	c = new CCircle(P1, P2, CircleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(c);

}

void AddcircleAction::undo()
{
	DeletedFig = pManager->DeleteFigure();
}

void AddcircleAction::redo()
{
	pManager->AddFigure(DeletedFig);
}
