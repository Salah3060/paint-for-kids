#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class figure_typeandcolor:public Action
{
	int numoffigbycolor;
	figures by_fig;
	colors by_color;
	Point p;
	CFigure* selected_fig;
	int incorrect = 0;
	int correct = 0;
public:
	figure_typeandcolor(ApplicationManager* pApp);
	 void ReadActionParameters();
	 void Execute(bool b);
	 void manage_typeandcolor();
	 void redo() {};
	 void undo() {};
};

