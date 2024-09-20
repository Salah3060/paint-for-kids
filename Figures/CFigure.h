#ifndef CFIGURE_H
#define CFIGURE_H
#include "..\defs.h"
#include "..\GUI\Output.h"
#include "fstream"
#include "..\GUI\UI_Info.h"
//Base class for all figures
class CFigure
{
protected:
	static int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static bool NewIsFilled;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	virtual  void decrementnumofshapes();
	void SetSelected(bool s);	 //select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual  bool checkselection(int x, int y) = 0;
	virtual int Getid() = 0;
	virtual Point& GetCenter() = 0;

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	//void ChngDrawClr(color Dclr);	//changes the figure's drawing color

	void ChngDrawClr(color Dclr);
	void clearColor();
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	virtual bool is_filled();
	///Decide the parameters that you should pass to each function	
	virtual bool isInsideWindowsBoundaries(const Point&) const = 0;
	virtual void resize(const Point&, int = 0) = 0;
	virtual int OutlineClickValidation(const Point&) = 0;
	virtual void move(const Point&) = 0;
	virtual void Save(fstream& OutFile) const = 0;	//Save the figure parameters to the file
	virtual void Load(string&) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) = 0;
	virtual color get_fillcolor();
	static void IsAllNewFilled(bool s = false);
	static void ResetID();


	//Save the figure parameters to the file
	//Load the figure parameters to the file
	 virtual void resetnumoffig();
	
		//Save the figure parameters to the file
		//Load the figure parameters to the file

};

#endif