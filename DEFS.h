#ifndef DEFS_H
#define DEFS_H
#include "GUI/UI_Info.h"
#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Recangle item in menu
	DRAW_CIRC,
	DRAW_TRIA,
	DRAW_SQUA,
	DRAW_HEXA,

	FUNC_ADD_IMAGE,
	FUNC_SELECT,
	FUNC_DELETE,
	FUNC_BRUSH,
	COLOR_BLACK,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_ORANGE,

	FUNC_UNDO,
	FUNC_REDO,
	FUNC_FILL,
	FUNC_MOVE,
	DRAWING_AREA,
	STATUS,
	EMPTY,
	FUNC_CLEAR_CANVAS,
	FUNC_STOP_REC,
	FUNC_START_REC,
	FUNC_PLAY_REC,
	FUNC_SAVE,
	FUNC_LOAD,
	ENTER_PLAY_MODE,
	FUNC_EXIT,
	FUNC_EXIT_playMode,
	ENTER_DRAW_MODE,
	BY_COLOR,
	BY_SHAPE,
	BY_COLOR_SHAPE,

	/// play Mood Sound 
	CorrectChoose ,
	WrongChoose,
	GameOver,
	WinSound, 
	// end of game 

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
	friend ostream& operator <<(ostream&, const Point&);
	friend Point operator+(const Point&, const Point&);
	friend Point operator-(const Point&, const Point&);

	friend Point operator/(const Point&, int);
public:


	Point operator =(const Point& p2)
	{
		x = p2.x;
		y = p2.y;
		return *this;

	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth = 3;	//default Width of figure borders 
	friend ostream& operator << (ostream&, const GfxInfo&);
};



#endif