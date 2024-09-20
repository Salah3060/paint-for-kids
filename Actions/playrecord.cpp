#include "playrecord.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

#include "Action.h"
playrecord::playrecord(ApplicationManager* pApp) :Action(pApp)
{
}

void playrecord::ReadActionParameters()
{
	
}	

void playrecord::Execute(bool b)
{ 
	pManager->Playrecord();

}

void playrecord::undo()
{
}

void playrecord::redo()
{
	
}

playrecord::~playrecord()
{
}
