#pragma once
#include "CFigure.h"
class CHexa : public CFigure
{
private:
	Point centre;
	int id;
	int l;  //side lenght of Hexa
	static int numofshapes;
public:

	CHexa(Point c, GfxInfo FigureGfxInfo);
	CHexa();

	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CHexa&);
	void Save(fstream&)const;
	void Load(string&);
	bool  checkselection(int x, int y);
	bool isInsideWindowsBoundaries(const Point&) const;
	void move(const Point&);
	int Getid();
	Point& GetCenter();
	int OutlineClickValidation(const Point&mousePosition);
	void resize(const Point&, int = 0);
	void PrintInfo(Output* pOut);
	//	void PrintInfo(Output* pOut);
	color get_fillcolor();
	static int getnumofshapes();
	 void decrementnumofshapes();
	 bool is_filled();
	 ~CHexa();
	 void resetnumoffig();
};

