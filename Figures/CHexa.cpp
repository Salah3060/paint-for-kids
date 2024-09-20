#include "CHexa.h"
#include "sstream"
#include <sstream>
#include "cstring"
#include<iostream>
#include"string.h"
#include<algorithm>
using namespace std;
int CHexa::numofshapes = 0;
CHexa::CHexa(Point c, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), centre(c), id(ID++), l(80)      //Here , if you want to change side lenght of Hexa 

{
	numofshapes++;
}
int CHexa::Getid()
{
	return id;
}
int CHexa::getnumofshapes()
{
	return numofshapes;
}
void CHexa::decrementnumofshapes()
{
	numofshapes--;
}
Point& CHexa::GetCenter()
{
	return centre;
}

int CHexa::OutlineClickValidation(const Point& mousePosition)
{
	if (sqrt(pow((mousePosition.x - centre.x), 2) + pow((mousePosition.y - centre.y), 2)) <= UI.wx + l) {
		return 1;
	};
	return 0;
}

void CHexa::resize(const Point& tempPoint, int)
{
	l = sqrt(pow((tempPoint.x - centre.x), 2) + pow((tempPoint.y - centre.y), 2));
}

bool CHexa::is_filled()
{
	return FigGfxInfo.isFilled;
}

bool CHexa::checkselection(int x, int y)
{

	int xc = centre.x, yc = centre.y;
	int small_height = l * 0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };


	int count = 0;
	for (int i = 0; i < 6; ++i) {
		int j = (i + 1) % 6;
		if ((ycoordinates[i] > y) != (ycoordinates[j] > y) &&
			x < (xcoordiantes[j] - xcoordiantes[i]) * (y - ycoordinates[i]) / (ycoordinates[j] - ycoordinates[i]) + xcoordiantes[i]) {
			count++;
		}
	}
	return count % 2 == 1;




}

void CHexa::Draw(Output* pOut) const
{
	int xc = centre.x, yc = centre.y;
	int small_height = l * 0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };

	pOut->Drawhexagon(xcoordiantes, ycoordinates, FigGfxInfo, Selected);

}

bool CHexa::isInsideWindowsBoundaries(const Point& newPos) const
{
	Point tCentre = newPos;
	if ((newPos.y) - l < (UI.ToolBarHeight + UI.wx) || (newPos.y) + sqrt(pow(l, 2) - pow(l / 2, 2)) >(UI.height - (UI.StatusBarHeight))
		|| ((newPos.x) + l) > (UI.width - UI.wx) || (newPos.x) - l < 0) return 0;
	return 1;
}
void CHexa::move(const Point& newPos)
{
	centre = newPos;
}
CHexa::CHexa() : l(80) { numofshapes++; };
void CHexa::Save(fstream& op) const
{

	op << "Hexagon: " << *this << endl;
}

void CHexa::Load(string& line)

{
	SetSelected(0);

	const int NoOfSpaces = 12; // increased the size to accommodate maximum possible data fields
	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces];


	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->id = stoi(datum[1]);
	this->centre.x = stoi(datum[2]);
	this->centre.y = stoi(datum[3]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[4]), stoi(datum[5]), stoi(datum[6]));
	this->FigGfxInfo.FillClr = color(stoi(datum[7]), stoi(datum[8]), stoi(datum[9]));
	this->FigGfxInfo.isFilled = stoi(datum[10]);
	this->FigGfxInfo.BorderWdth = stoi(datum[11]);
}


ostream& operator<<(ostream& op, const CHexa& Fig) {
	op << Fig.id << " " << Fig.centre << " " << Fig.FigGfxInfo << endl;
	return op;
};
void CHexa::PrintInfo(Output* pOut)
{
	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting
	string printed = " Figure is Hexa         Figure id : " + to_string(id) + "        Side lenght : " + to_string(l)
		+ "       Centre : (" + to_string(centre.x) + "," + to_string(centre.y) + ")";
	pOut->PrintMessage(printed);
}
color CHexa::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
CHexa::~CHexa()
{
	numofshapes--;
}
void CHexa::resetnumoffig()
{
	numofshapes = 0;
}