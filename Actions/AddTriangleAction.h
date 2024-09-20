#pragma once
#include "Action.h"
#include"..\Figures\CTriangle.h"

class AddTriangleAction :
    public Action
{
private :
    Point P1, P2, P3;
    GfxInfo TriangleGfxInfo;
    CFigure* DeletedFig;
 
    CTriangle* T;
public :
    AddTriangleAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    void addundofirst(Action* pAct);
   void Execute(bool b) ;
   void undo();
     void redo();
   

};

