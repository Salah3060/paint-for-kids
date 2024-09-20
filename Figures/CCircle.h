#pragma once
#include "CFigure.h"
#include "fstream"
class CCircle : public CFigure
{
private:
	Point P1, P2;
	int id;
	static int numofshapes;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	Point& GetCenter();

	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool checkselection(int x, int y);
	void Save(fstream&) const;
	void Load(string&);
	friend ostream& operator<<(ostream&, const CCircle&);
	void move(const Point&);
	bool isInsideWindowsBoundaries(const Point&) const;
	void resize(const Point&, int = 0);
	int OutlineClickValidation(const Point& mousePosition);

	int Getid();
	void PrintInfo(Output* pOut);
	color get_fillcolor();
	static int getnumofshapes();
	void decrementnumofshapes();
	bool is_filled();
	~CCircle();
	void resetnumoffig();
};


