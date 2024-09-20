#include "CTriangle.h"
#include <sstream>
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	id = ID;
	ID++;
	numofshapes++;
}
int CTriangle::numofshapes = 0;

CTriangle::CTriangle() { numofshapes++; };

int CTriangle::Getid()
{
	return id;
}
bool CTriangle::is_filled()
{
	return FigGfxInfo.isFilled;
}
Point& CTriangle::GetCenter()
{

	Point* p = new Point;
	*p = { (P1.x + P2.x + P3.x) / 3, (P1.y + P2.y + P3.y) / 3 };
	return *p;


}
void CTriangle::resize(const Point& tempPoint, int cornerNumber)
{
	if (cornerNumber == 1) {
		P1 = tempPoint;
	}
	else if (cornerNumber == 2) {
		P2 = tempPoint;
	}
	else P3 = tempPoint;

}
int CTriangle::OutlineClickValidation(const Point& tempPoint)
{		//checks the distance between where the user has clicked a corner
	if (sqrt(pow((tempPoint.x - P1.x), 2) + pow((tempPoint.y - P1.y), 2)) <= UI.wx) {
		return 1;
	}
	else if (sqrt(pow((tempPoint.x - P2.x), 2) + pow((tempPoint.y - P2.y), 2)) <= UI.wx) {
		return 2;
	}
	else return 3;
	return 0;
}
int CTriangle::getnumofshapes()
{
	return numofshapes;
}
void CTriangle::decrementnumofshapes()
{
	numofshapes--;
}


void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, FigGfxInfo, Selected);
}
bool CTriangle::checkselection(int x, int y)
{

	int x1 = P1.x;	int x2 = P2.x;	int x3 = P3.x;
	int y1 = P1.y;	int y2 = P2.y;	int y3 = P3.y;

	double denominator = ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	double a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denominator;
	double b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denominator;
	double c = 1 - a - b;

	if (a >= 0 && b >= 0 && c >= 0)
		return true;

	return false;


}
void CTriangle::Save(fstream& op) const
{
	op << "Triangle: " << *this << endl;
}
void CTriangle::Load(string& line)
{
	SetSelected(0);
	const int NoOfSpaces = 16;


	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces]; // increased the size to accommodate maximum possible data fields

	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->id = stoi(datum[1]);
	this->P1.x = stoi(datum[2]);
	this->P1.y = stoi(datum[3]);
	this->P2.x = stoi(datum[4]);
	this->P2.y = stoi(datum[5]);
	this->P3.x = stoi(datum[6]);
	this->P3.y = stoi(datum[7]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[8]), stoi(datum[9]), stoi(datum[10]));
	this->FigGfxInfo.FillClr = color(stoi(datum[11]), stoi(datum[12]), stoi(datum[13]));
	this->FigGfxInfo.isFilled = (unsigned int)stoi(datum[14]);
	this->FigGfxInfo.BorderWdth = (unsigned int)stoi(datum[15]);
}

void CTriangle::move(const Point& newPos)
{
	Point center = GetCenter();
	P2 = P2 + newPos - center;
	P3 = P3 + newPos - center;
	P1 = P1 + newPos - center;
}

bool CTriangle::isInsideWindowsBoundaries(const Point& newPos) const
{
	Point tP1, tP2, tP3;
	tP2 = tP2 + newPos - tP1;
	tP3 = tP3 + newPos - tP1;
	tP1 = newPos;
	if ((tP1.y) < (UI.ToolBarHeight + UI.wx) || (tP2.y) < (UI.ToolBarHeight + UI.wx) || (tP3.y) < (UI.ToolBarHeight + UI.wx) || (tP1.y) > (UI.height - UI.StatusBarHeight + UI.wx)
		|| (tP2.y) > (UI.height - UI.StatusBarHeight + UI.wx) || (tP3.y) > (UI.height - UI.StatusBarHeight + UI.wx))
		return false;
	return true;
}


ostream& operator<<(ostream& op, const CTriangle& Fig) {
	op << Fig.id << " " << Fig.P1 << " " << Fig.P2 << " " << Fig.P3 << " " << " " << Fig.FigGfxInfo << endl;
	return op;
}
void CTriangle::PrintInfo(Output* pOut)
{

	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting

	string printed = "Fiure is Triangle      Figure id : " + to_string(id) +
		"        Fisrt Corner :(" + to_string(P1.x) + "," + to_string(P1.y) + ")"
		+ "        Second Corner :(" + to_string(P2.x) + "," + to_string(P2.y) + ")"
		+ "        Third Corner :(" + to_string(P3.x) + "," + to_string(P3.y) + ")";
	pOut->PrintMessage(printed);

}
color CTriangle::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
CTriangle::~CTriangle()
{
	numofshapes--;
}
void CTriangle::resetnumoffig()
{
	numofshapes = 0;
}
