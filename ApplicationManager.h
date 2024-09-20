#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
class Action;
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxFigCount = 200, maxActionCount = 5 };	//Max no of figures


private:
	Action** arr_recActions;
	Action* ActListun[maxActionCount];       //actual array of actions
	Action* ActListre[maxActionCount];
	int ActionCountun;
	int ActionCountre;
	int FigCount;		//Actual number of figures
	int DeletedFigCount;

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action* pLastAct;
	color fill[5];
	color brush[5];
	Point Pos[5];
	CFigure* DeletedFig;

	CFigure* Selected_Figure;
	int counter = 0;
	CFigure* DeletedFigList[MaxFigCount];

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
public:
	static int iX;
	static int iY;
	static int countpos;
	static int countrepos;
	//static int countfill;
	static int countbrush;
	ApplicationManager();
	~ApplicationManager();
	void ClearAll(bool calledfromplay=false);
	void clearUndoRedoFuncs();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType, int numofrec = -1); //Creates an action and executes it
	void addfillcolor(color c, int i);
	void addbrushcolor(color c);
	// -- Figures Management Functions
	void Playrecord();
	void RemoveFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* DeleteFigure();          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y); //Search for a figure given a point inside the figure
	void setSelectedFigure(CFigure* const);
	void AddFigure(CFigure* pFig);  //Adds a new figure to the FigList
	void set_figure(CFigure*);
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface();	//Redraws all the drawing window	
	void SaveAll(fstream&) const;
	void addToUndo(Action* pAct);
	void addToRedo();

	Action* GetLastUndo();
	CFigure* GetLastFigure();

	Action* GetLastRedo();
	void addPoint(Point p);

	Point getpoint(int index);
	
	
	void addColor(color c);
	void getColor();
	CFigure* GetSelected_Figure();
	void DeleteFunction();
	void SetSelectedFig(CFigure* S);
	void DeleteFunctionForPlayMood(CFigure* Del);
	void CopyDeletedFigToFiglist();
	void AddDeletedFig(CFigure* del);
	int get_numofcolor(color);
	int numof_figurewithcolor(figures, colors);
	color get_fillcolor(colors);
	string color_TO_String(colors c);
	string figur_TO_String(figures);
	color get_indx_fillcolor(int indx);
	color get_indx_brushcolor(int indx);

};


#endif