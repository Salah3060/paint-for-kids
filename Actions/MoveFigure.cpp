#include "MoveFigure.h"
#include "DeleteAction.h"
#include "../CMUgraphicsLib/auxil.h"
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"

moveFigure::moveFigure(ApplicationManager* pApp, bool byDragging) :Action(pApp), newPos{ -1,-1 }, byDragging(byDragging), cFigure(nullptr) {

};

void moveFigure::ReadActionParameters() {
	// Obtain pointers to the Output, Input, and currently selected figure from the manager

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	cFigure = pManager->GetSelected_Figure();

	// Check if a figure is selected
	if (cFigure != nullptr)
	{
		// Get the center of the selected figure for undoing and redoing
		newPos = (cFigure->GetCenter());
		// Prompt the user to click a point to move the figure to

		pOut->PrintMessage("Click a point to move the figure to.");
		pIn->GetPointClicked(newPos.x, newPos.y);

		// Clear the status bar after obtaining the new position
		pOut->ClearStatusBar();
	}
	else {
		// Display a message if no figure is selected
		pOut->PrintMessage("Choose a figure first then try again!");
		// Pause for 1000 milliseconds to display the message
		Pause(1000);
		pManager->GetInput()->FlushMouseQueue(); // Clear the mouse queue to prevent spamming the move button without a selected figure
		pOut->ClearStatusBar();
	}
}
void moveFigure::Execute(bool b) {
	// Obtain the selected figure from the manager
	cFigure = pManager->GetSelected_Figure();
	// Check if dragging is not enabled

	if (!byDragging)
	{
		if (b)
		{
			if (cFigure != nullptr)
			{
				// Read the action parameters if conditions are met
				ReadActionParameters();

			}
			// Move the figure (the move function may be called based on conditions)
		}move();
	}
	// If dragging is enabled, execute the moveByDragging function
	else moveByDragging();
}

void moveFigure::move(bool notaReverseAction) {
	// Check if dragging is not enabled, a figure is selected, and it's not a reverse action
	if (!byDragging && cFigure != nullptr && notaReverseAction == true)
	{
		lastPoint = cFigure->GetCenter();
	}
	// Set the current figure in the manager
	pManager->set_figure(cFigure);

	// Check if the new position is within the application window boundaries
	if ((newPos.x <= UI.width - 5 && newPos.x > 0) && (newPos.y < UI.height - UI.StatusBarHeight - 5) && (newPos.y > UI.ToolBarHeight + 5)) {
		// Check if the figure is inside the specified boundaries
		if (cFigure->isInsideWindowsBoundaries(newPos))
		{
			// Move the figure to the new position
			cFigure->move(newPos);
		}
		else {
			// Display an error message for an invalid position
			pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
			Pause(1000);
			pManager->GetOutput()->ClearStatusBar();
		}
		pManager->UpdateInterface();
	}
}

void moveFigure::moveByDragging() {
	Input* pIn = pManager->GetInput();
	pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y); // Get the button state and store the current coordinates in newPos.x and newPos.y

	// Check if the current coordinates are within the selection boundaries of the figure
	if (cFigure->checkselection(newPos.x, newPos.y) == true) {
		// Store the center of the figure as the last point
		lastPoint = cFigure->GetCenter();
		Sleep(200);			// necessary delay to capture the users double tap on a shape

		// Continue while the left or right mouse button is down
		while (pIn->GetButtonState(RIGHT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN
			|| pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN) {
			// Checks if the new point would still make the figure inside the application window boundaries
			if (cFigure->isInsideWindowsBoundaries(newPos))
				// Move the figure
				move();
			else
			{
				// Display an error message for an invalid position
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				break;
			}
			Sleep(80); // necessary delay to avoid breaking the GUI

			// Print information about the figure and update the interface
			cFigure->PrintInfo(pManager->GetOutput());
			pManager->UpdateInterface();

		}
	}
}

void moveFigure::addundofirst(Action* pAct)	// Add the current state of the moveFigure action to the undo array

{
	pManager->addToUndo(this);
}
// Undo the moveFigure action by swapping the last point and new position, then moving back to the original position
void moveFigure::undo()
{
	swap(lastPoint, newPos);
	move(false);
}
// Redo the moveFigure action by swapping the last point and new position, then moving back to the modified position
void moveFigure::redo()
{
	swap(lastPoint, newPos);
	move(false);
}