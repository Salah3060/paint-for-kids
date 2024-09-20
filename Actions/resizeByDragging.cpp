#include "resizeByDragging.h"
#include "../CMUgraphicsLib/auxil.h"

resizeByDragging::resizeByDragging(ApplicationManager* pApp) : Action(pApp)
{
}

// Execute function for resizeByDragging, responsible for resizing a figure by dragging its corner
void resizeByDragging::Execute(bool b)
{
	if (b) {
		Point newPos;
		Input* pIn = pManager->GetInput();
		CFigure* sFigure = pManager->GetSelected_Figure();

		pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y);  // Get the current coordinates of the mouse
		
		// Check if the mouse is on the outlines of the selected figure
		int cornerNumber = sFigure->OutlineClickValidation(newPos);
		if (cornerNumber) { // checks if the mouse is on the outlines of the selected figure
			Sleep(100); // Necessary delay to capture the user's double-tap on a shape
			
			// Continue while the left or right mouse button is down
			while (pIn->GetButtonState(RIGHT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN ||
				pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN)
			{
				if (sFigure->isInsideWindowsBoundaries(sFigure->GetCenter()))
					sFigure->resize(newPos, cornerNumber);
				else
				{
					pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
					Pause(1000);
					pManager->GetOutput()->ClearStatusBar();
					break;
				}
				Sleep(80); // necessary delay to avoid breaking the gui
				sFigure->PrintInfo(pManager->GetOutput());
				pManager->UpdateInterface();

			}
		}
	}
}

void resizeByDragging::ReadActionParameters()
{

}
