#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 



AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{
	//pManager->GetOutput()->PrintMessage(" PLEASE , Wait until sound finished ");
	
}

void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);


	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click second corner");
	pIn->GetPointClicked(P2.x, P2.y);
	while (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddRectAction::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}

//Execute the action
void AddRectAction::Execute(bool b) 
{

	
	if (b)
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);


}

void AddRectAction::undo()
{
	DeletedFig = pManager->DeleteFigure();
}

void AddRectAction::redo()
{
	pManager->AddFigure(DeletedFig);
}
