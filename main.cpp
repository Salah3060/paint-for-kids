#include "ApplicationManager.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
#include "Actions/playSound.h"
#include <cstdlib> 








int main()
{



	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;


	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while(ActType != FUNC_EXIT && ActType !=FUNC_EXIT_playMode);
	
	PlaySound(".\\sounds\\EndGame.wav", NULL, SND_ASYNC | SND_FILENAME);
	Sleep(600);

	
	return 0;
}

