#pragma once
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


class clearAll : public Action
{
public:
	 clearAll(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);
	
	virtual void undo();
	virtual void redo();

};

