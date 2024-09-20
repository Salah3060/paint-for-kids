#include "CRectangle.h"
#include <sstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	id = ID;
	ID++;
	numofshapes++;
}
int CRectangle::numofshapes = 0;

int CRectangle::getnumofshapes()
{
	return numofshapes;
}
void CRectangle::decrementnumofshapes()
{
	numofshapes--;
}
bool CRectangle::is_filled()
{
	return FigGfxInfo.isFilled;
}
int CRectangle::Getid()
{
	return id;
}
void CRectangle::resize(const Point& tempPoint, int cornerNumber)
{
	if (cornerNumber == 1) // if the OutlineClickValidation returns 1 then the user has clicked on the first corner
	{
		Corner1 = tempPoint;
	}
	else Corner2 = tempPoint;
}
int CRectangle::OutlineClickValidation(const Point& tempPoint)
{
	if (sqrt(pow((tempPoint.x - Corner1.x), 2) + pow((tempPoint.y - Corner1.y), 2)) <= UI.wx) {
		return 1;
	}
	else if (sqrt(pow((tempPoint.x - Corner2.x), 2) + pow((tempPoint.y - Corner2.y), 2)) <= UI.wx) {
		return 2;
	}return 0;
}
CRectangle::CRectangle() { numofshapes++; }
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
ostream& operator<<(ostream& op, const CRectangle& Fig)
{
	op << Fig.id << " " << Fig.Corner1 << " " << Fig.Corner2 << " " << Fig.FigGfxInfo << endl;
	return op;
}
void CRectangle::Save(fstream& op) const
{
	op << "Rectangle: " << *this << endl;
}

void CRectangle::Load(string& line)
{
	SetSelected(0);

	/* Some Constants used to save shapes' info */
	const int NoOfSpaces = 14;

	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces]; // increased the size to accommodate maximum possible data fields

	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->id = stoi(datum[1]);
	this->Corner1.x = stoi(datum[2]);
	this->Corner1.y = stoi(datum[3]);
	this->Corner2.x = stoi(datum[4]);
	this->Corner2.y = stoi(datum[5]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);
}
void CRectangle::move(const Point& newPos)
{
	Point center = (Corner1 + Corner2) / 2;
	Corner2 = newPos + Corner2 - center;
	Corner1 = newPos + Corner1 - center;
}
bool CRectangle::checkselection(int x, int y)
{
	if ((x >= Corner1.x && x <= Corner2.x) && (y >= Corner1.y && y <= Corner2.y))
	{
		return true;
	}
	if ((x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y))
	{
		return true;
	}
	if ((x >= Corner1.x && x <= Corner2.x) && (y <= Corner1.y && y >= Corner2.y))
	{
		return true;
	}

	if ((x <= Corner1.x && x >= Corner2.x) && (y <= Corner1.y && y >= Corner2.y))
	{
		return true;
	}



	return false;

}
bool CRectangle::isInsideWindowsBoundaries(const Point& newPos) const
{

	Point tCorner2 = newPos + Corner2 - (Corner1 + Corner2) / 2;
	Point tCorner1 = newPos + Corner1 - (Corner1 + Corner2) / 2;
	if ((tCorner1.y > UI.ToolBarHeight + UI.wx && tCorner1.y < UI.height - UI.StatusBarHeight - UI.wx) && (tCorner2.y > UI.ToolBarHeight + UI.wx && tCorner2.y < UI.height - UI.StatusBarHeight - UI.wx)) //check if the second corner will be valid
		return 1;
	return 0;
}
void CRectangle::PrintInfo(Output* pOut)
{
	/// calcuate  data of figure 
	int hieght = abs(Corner1.y - Corner2.y);
	int widght = abs(Corner1.x - Corner2.x);

	// concatination to print one sting contaion all data of figure

		// to_string ()  is a function that cast int to strting

	string printed = "Figure is Rectangle   Figure id : " + to_string(id) +
		"   Fisrt Corner :(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		+ "  Second Corner :(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")"
		+ "   height " + to_string(hieght) + "    width " + to_string(widght) + "     (To Resize by Drag click the top left corner or bottom Right) ";
	pOut->PrintMessage(printed);

}
color CRectangle::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}

Point& CRectangle::GetCenter()
{
	Point* p = new Point{ (Corner1.x + Corner2.x) / 2,
		(Corner1.y + Corner2.y) / 2 };


	return *p;
}
CRectangle::~CRectangle()
{
	numofshapes--;
}
void CRectangle::resetnumoffig()
{
	numofshapes = 0;
}



