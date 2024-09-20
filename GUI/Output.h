#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void DrawImage(const string path, int x, int y, int Iwidth, int Iheight) const;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void createIntro();
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawCirc(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a Circle
	void Drawrtriangle(int x1, int y1, int x2, int y2, int x3, int y3, GfxInfo RectGfxInfo, bool selected=false) const;
	void Drawhexagon(const int* xcoordinates, const int* ycoordinates, GfxInfo RectGfxInfo, bool selected=false) const;
	///TODO:Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	void Names();                      

	void SetDraColor(color c);
	void SetFillColor(color c);


	
	~Output();
};

#endif