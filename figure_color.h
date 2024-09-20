#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class figure_color :public Action
{
	colors by_color;
	Point p;
	CFigure* selected_fig;
	int incorrect = 0;
	int correct = 0;
public:
	figure_color(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);
	void manage_by_color(color, int n);
	void redo() {};
	void undo() {};
};

