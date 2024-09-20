#pragma once
#include "CFigure.h"

class CTriangle :
	public CFigure
{
private:
	Point P1, P2, P3;
	int id;
	static int numofshapes;
public:

	CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	bool checkselection(int x, int y);
	void Save(fstream&)const;
	friend ostream& operator<<(ostream&, const CTriangle&);
	void Load(string&);
	void move(const Point&);
	bool isInsideWindowsBoundaries(const Point&) const;
	int Getid();
	Point& GetCenter();
	void resize(const Point&, int = 0);
	int OutlineClickValidation(const Point&);
	void PrintInfo(Output* pOut);
	color get_fillcolor();
	static int getnumofshapes();
	 void decrementnumofshapes();
	 bool is_filled();
	 ~CTriangle();
	 void resetnumoffig();
};
