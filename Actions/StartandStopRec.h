#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class StartandStopRec : public Action
{
	ActionType current_action;
	bool stop_rec = false;
public:
	StartandStopRec(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);
	~StartandStopRec();
	void redo() {};
	void undo() {};
};

