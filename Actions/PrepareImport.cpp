#include "PrepareImport.h"
#include "../ApplicationManager.h"
#include "fstream"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"

#include "../DEFS.h"
#include <sstream>
#include "../CMUgraphicsLib/auxil.h"

PrepareImport::PrepareImport(ApplicationManager* pApp) :Action(pApp) {};

// Read action parameters for PrepareImport, prompting the user to enter a file name
void PrepareImport::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Enter The file name or press ESC to cancel.");
	name = pManager->GetInput()->GetString(pManager->GetOutput());

}

// Execute function for PrepareImport, responsible for preparing and loading data from a file
void PrepareImport::Execute(bool b) {
	ReadActionParameters();
	// checks if the button isn't "-1" i.e ESC
	name += ".txt";
	fstream* OutputFile = (name != "-1.txt") ? new fstream(name, ios::in) : (pManager->GetOutput()->PrintMessage("Load File Cancelled."), 0);
	pManager->GetOutput()->ClearStatusBar();

	if (OutputFile != nullptr) {
		{if (OutputFile->is_open())
		{
			// Clear all existing figures in the manager
			pManager->ClearAll();
			// Temporary pointer to hold a figure object
			CFigure* p = nullptr;
			string line;

			while (getline(*OutputFile, line)) {
				// Determine the type of figure based on the line and create the corresponding object
				if (line.find("Triangle:") != string::npos) {
					p = new CTriangle();
					p->Load(line);  // Load data from the line into the figure object
					pManager->AddFigure(p);
				}
				else if (line.find("Hexagon:") != string::npos) {
					p = new CHexa();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (line.find("Rectangle:") != string::npos) {
					p = new CRectangle();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (line.find("Circle:") != string::npos) {
					p = new CCircle();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (line.find("Square:") != string::npos) {

					p = new CSquare();
					p->Load(line);
					pManager->AddFigure(p);
				}
			}
			// Clear the draw area and update the interface after loading all figures
			pManager->GetOutput()->ClearDrawArea();
			pManager->UpdateInterface();
		}

		else {
			// Display an error message for file not found
			pManager->GetOutput()->PrintMessage("File Not Found.");
			Pause(2000);
			pManager->GetOutput()->ClearStatusBar();
		}
		}
	}
}
void PrepareImport::undo()
{
}
void PrepareImport::redo()
{
}
;