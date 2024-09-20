#include "to_drawmood.h"

to_drawmood::to_drawmood(ApplicationManager *pApp):Action(pApp)
{

}
void to_drawmood::Execute(bool b)
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();

	pOut->CreateDrawToolBar();

	pManager->CopyDeletedFigToFiglist();

	pManager->UpdateInterface();


	pOut->PrintMessage(" Swithced To Draw Mood");
	
}
void to_drawmood::ReadActionParameters()
{

}