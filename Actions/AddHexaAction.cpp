#include "AddHexaAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CHexa.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction( ApplicationManager * pApp):Action(pApp)
{
	
}
void AddHexaAction::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("New Hexagon: Click at centre point ");
	int invalid = 1;

	do
	{

		int sidelenght = 80;               //   !!! if side lenght is changed from Hexa class it must be Changed here !!!
		int small_height = sidelenght * 0.87;         // cos(60)  (from geometry of shape)
		int small_lenght = sidelenght * 0.5;       // sin(60) (from geometry of shape)


		pIn->GetPointClicked(P1.x, P1.y);  // CENTRE OF HEXA
		if ((P1.y) - small_height< (UI.ToolBarHeight + 5) || (P1.y) + small_height > (UI.height - UI.StatusBarHeight + 5)  //  vertical validation : window hieght - tool bat height + 5 to be in safe
			|| ((P1.x) + sidelenght) > (UI.width - 5) || (P1.x) - sidelenght < 0)           // horizontal validation 
		{
			pOut->PrintMessage("Invalid centre , click anthor centre ");

		}
		else invalid = 0;

	} while (invalid);

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddHexaAction::Execute(bool b)
{
	if (b)
	ReadActionParameters();
	/// create New Hexa

	 H = new CHexa(P1, HexaGfxInfo);
	// Add Hexa to Fig List

	pManager->AddFigure(H);
}

void AddHexaAction::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}

void AddHexaAction::undo()
{
	DeletedFig = pManager->DeleteFigure();
}

void AddHexaAction::redo()
{
	pManager->AddFigure(DeletedFig);
}

