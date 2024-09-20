
#pragma once
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "AddRectAction.h"
#include"AddcircleAction.h"
#include"AddTriangleAction.h"
#include"AddSquareAction.h"
#include"AddHexaAction.h"
#include"SelectAction.h"
#include "PrepareExport.h"
#include "PrepareImport.h"
#include "fstream"
#include "..\Figures/CCircle.h"
class RedoAction : public Action
{
public:

	RedoAction(ApplicationManager* pApp);
	void AddToActions(Action* Act);


	void Execute(bool b);
	void ReadActionParameters();





};