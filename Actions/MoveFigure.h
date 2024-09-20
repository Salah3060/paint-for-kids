#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class moveFigure : public Action
{
	Point newPos;
	Point lastPoint;

	CFigure* cFigure;
	bool byDragging;
public:
	moveFigure(ApplicationManager* pApp, bool byDragging = 0);
	void ReadActionParameters();
	void move(bool notaReverseAction = true);
	void moveByDragging();
	void addundofirst(Action* pAct);
	void Execute(bool b);
	void undo();
	void redo();
};