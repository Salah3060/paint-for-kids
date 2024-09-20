#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class to_drawmood :public Action
{
public:
	to_drawmood (ApplicationManager* pApp);
	 void Execute(bool b);
	 void ReadActionParameters();
	void redo() {};
	void undo() {};
};

