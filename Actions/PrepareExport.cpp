#include "PrepareExport.h"
#include "../ApplicationManager.h"
#include "fstream"
#include "../CMUgraphicsLib/auxil.h"

PrepareExport::PrepareExport(ApplicationManager* pApp) :Action(pApp) {};

// Read action parameters for PrepareExport, prompting the user to enter a file name
void PrepareExport::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Enter The file name without .txt or press ESC to cancel.");
	name = pManager->GetInput()->GetString(pManager->GetOutput());
}

// Execute function for PrepareExport, responsible for preparing and saving data to a file
void PrepareExport::Execute(bool b) {
	ReadActionParameters();     // Read action parameters to get the file name from the user
	name += ".txt";     // Append ".txt" to the file name

	// Check if the file name is not "-1.txt" (ESC) and create a file stream
	fstream* OutputFile = (name != "-1.txt") ? new fstream(name, ios::out | ios::in) : (pManager->GetOutput()->PrintMessage("Save File Cancelled."), 0);

	pManager->GetOutput()->ClearStatusBar();

	// Check if the OutputFile is not nullptr
	if (OutputFile != nullptr) {
		OutputFile->clear();
		OutputFile->close();
		// Delete the OutputFile pointer and nullptring it
		delete OutputFile;
		OutputFile = nullptr;

		// Create a new file stream with append and out access mode
		OutputFile = new fstream(name, ios::app | ios::out);

		// Save all figures' data to the file
		pManager->SaveAll(*OutputFile); // 		Now Each Figures' data will be written after its name and id

	}
}
void PrepareExport::undo()
{
}
void PrepareExport::redo()
{
}
;