#pragma once
#include "Action.h"
class resizeByDragging :
	public Action
{
public:
	resizeByDragging(ApplicationManager* pApp);
	void Execute(bool b);
	void ReadActionParameters();
};

