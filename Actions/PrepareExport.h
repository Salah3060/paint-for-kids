#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class PrepareExport :
    public Action
{
    string name;
public:
    PrepareExport(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute(bool b);
     void undo();
     void redo();
};

