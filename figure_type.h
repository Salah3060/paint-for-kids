#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
class figure_type : public Action
{
	int numoffigure;
	figures by_fig;
	Point p;
	CFigure* selected_fig;
	int incorrect = 0;
	int correct=0;
public:
	figure_type(ApplicationManager* pApp);
	 void ReadActionParameters();
	 void Execute(bool b);
	 void manage_byfigure();
	 void redo() {};
	 void undo() {};
};

