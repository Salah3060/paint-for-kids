#include "CSquare.h"
#include "sstream"
CSquare::CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	P1 = p1;
	P2 = p2;
	id = ID;
	ID++;
	numofshapes++;
}
int CSquare::numofshapes = 0;
int CSquare::getnumofshapes()
{
	return numofshapes;
}
void CSquare::decrementnumofshapes()
{
	numofshapes--;
}

int CSquare::Getid()
{
	return id;
}
void CSquare::resize(const Point& tempPoint, int cornerNumber)
{
	if (cornerNumber == 1)
		P1 = tempPoint;
	else P2 = tempPoint;

}
int CSquare::OutlineClickValidation(const Point& tempPoint)
{
	if (sqrt(pow((tempPoint.x - P1.x), 2) + pow((tempPoint.y - P1.y), 2)) <= FigGfxInfo.BorderWdth) {
		return 1;
	}
	else if (sqrt(pow((tempPoint.x - P2.x), 2) + pow((tempPoint.y - P2.y), 2)) <= FigGfxInfo.BorderWdth) {
		return 2;
	}return 0;
}
bool CSquare::is_filled()
{
	return FigGfxInfo.isFilled;
}
Point& CSquare::GetCenter()
{
	return (P1 + P2) / 2;
}

CSquare::CSquare() { numofshapes++; };

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawRect(P1, P2, FigGfxInfo, Selected);
}
void CSquare::Save(fstream& op) const
{

	op << "Square: " << *this << endl;
}
void CSquare::Load(string& line)
{
	SetSelected(0);
	const int NoOfSpaces = 14;

	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces]; // increased the size to accommodate maximum possible data fields

	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}	this->id = stoi(datum[1]);

	this->P1.x = stoi(datum[2]);
	this->P1.y = stoi(datum[3]);
	this->P2.x = stoi(datum[4]);
	this->P2.y = stoi(datum[5]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);

}

ostream& operator<<(ostream& op, const CSquare& Fig) {
	op << Fig.id << " " << Fig.P1 << " " << Fig.P2 << " " << Fig.FigGfxInfo << endl;
	return op;
};
bool CSquare::checkselection(int x, int y)
{
	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) && ((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
	{
		return true;
	}
	return false;

}

void CSquare::move(const Point& newPos)
{
	Point Center = (P2 + P1) / 2;
	P2 = newPos + P2 - Center;
	P1 = newPos + P1 - Center;
}

bool CSquare::isInsideWindowsBoundaries(const Point& newPos) const
{

	Point P2 = newPos + CSquare::P2 - (CSquare::P2 + CSquare::P1) / 2;
	Point P1 = newPos + CSquare::P1 - (CSquare::P2 + CSquare::P1) / 2;
	if ((!(P1.y > UI.ToolBarHeight + UI.wx && P1.y < UI.height - UI.StatusBarHeight - UI.wx)) || (!(P2.y > UI.ToolBarHeight + UI.wx && P2.y < UI.height - UI.StatusBarHeight - UI.wx)) || (P1.x < UI.wx || P2.x >= UI.width - UI.wx))
		return 0;
	return 1;
}
void CSquare::PrintInfo(Output* pOut)
{
	int hieght = abs(P1.y - P2.y);
	int width = abs(P1.x - P2.x);

	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting

	string printed = "Fiure is Square   Figure id : " + to_string(id) +
		"     Fisrt Corner :(" + to_string(P1.x) + "," + to_string(P1.y) + ")"
		+ "   Second Corner :(" + to_string(P2.x) + "," + to_string(P2.y) + ")"
		+ "  height " + to_string(hieght) + "    width " + to_string(width)  // hieght = widght becuase it's a square
		+ "   (To Resize by Drag click the top left corner or bottom Right) ";

	pOut->PrintMessage(printed);

}
color CSquare::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
CSquare::~CSquare()
{
	numofshapes--;
}
void CSquare::resetnumoffig()
{
	numofshapes = 0;
}
