#pragma once
#pragma once
#include"Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
class playrecord :public Action
{

public:
	playrecord(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);

     void undo();
	 void redo();

	~playrecord();
};

