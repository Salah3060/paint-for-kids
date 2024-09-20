#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	int id;
	static int numofshapes;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	void move(const Point& newPos);

	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CRectangle&);
	void Save(fstream&)const;
	void Load(string&);
	bool isInsideWindowsBoundaries(const Point&) const;
	bool checkselection(int x, int y);
	int Getid();
	void resize(const Point&, int = 0);
	int OutlineClickValidation(const Point&tempPoint);
	void PrintInfo(Output* pOut);
	color get_fillcolor();
	//void PrintInfo(Output* pOut);
	Point& GetCenter();
	static int getnumofshapes();
	 void decrementnumofshapes();
	 bool is_filled();
	 ~CRectangle();
	 void resetnumoffig();
};

#endif