#include "CCircle.h"
#include <fstream>
#include <sstream>
#include "cstring"
#include<iostream>
#include"string.h"
#include "..\GUI\Output.h"
#include "..\GUI\input.h"

using namespace std;
ostream& operator<<(ostream& op, const color& c) {
	op << int(c.ucRed) << " " << int(c.ucGreen) << " " << int(c.ucBlue);
	return op;
}
int CCircle::numofshapes = 0;
CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	id = ID;
	ID++;
	numofshapes++;
}
int CCircle::getnumofshapes()
{
	return numofshapes;
}
void CCircle::decrementnumofshapes()
{
	numofshapes--;
}
Point& CCircle::GetCenter()
{
	return P2;
}

int CCircle::Getid()
{
	return id;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a circle  on the screen	
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);

}
CCircle::CCircle() { numofshapes++; };

ostream& operator<<(ostream& op, const CCircle& c)
{
	op << c.ID << " " << c.P1 << " " << c.P2 << " " << c.FigGfxInfo << endl;
	return op;
}


void CCircle::Save(fstream& op) const {
	op << "Circle: " << *this << endl;
}
void CCircle::Load(string& line)
{

	/* Some Constants used to save shapes' info */
	const int NoOfSpaces = 14;


	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[14]; // increased the size to accommodate maximum possible data fields


	for (int i = 0; i < 14; i++) {
		ss >> datum[i];
	}
	SetSelected(0);
	this->id = stoi(datum[1]);
	this->P1.x = stoi(datum[2]);
	this->P1.y = stoi(datum[3]);
	this->P2.x = stoi(datum[4]);
	this->P2.y = stoi(datum[5]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);



}
bool CCircle::checkselection(int x, int y)
{
	int Cicle_radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	int Given_radius = sqrt((P1.x - x) * (P1.x - x) + (P1.y - y) * (P1.y - y));
	if (Cicle_radius >= Given_radius)
	{
		return true;
	}
	return false;
};
void CCircle::move(const Point& p) {
	P2 = P2 + p - P1;
	P1 = p;
}
bool CCircle::isInsideWindowsBoundaries(const Point& p) const
{
	Point tempP2 = P2 + p - P1;
	Point tempP1 = p;
	int r = sqrt((tempP1.x - tempP2.x) * (tempP1.x - tempP2.x) + (tempP1.y - tempP2.y) * (tempP1.y - tempP2.y));
	return !(!((tempP1.y - r) > UI.ToolBarHeight + UI.wx && (tempP1.y + r) < UI.height - UI.StatusBarHeight) || (tempP1.x - r) < UI.wx || (tempP1.x + r) >= UI.width - UI.wx);
}
void CCircle::resize(const Point& tempPoint, int)
{
	P2 = tempPoint;
}
int CCircle::OutlineClickValidation(const Point& mousePosition)
{
	int Cicle_radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	int ClickRadius = sqrt(pow((mousePosition.x - P1.x), 2) + pow((mousePosition.y - P1.y), 2));
	if (ClickRadius <= Cicle_radius + FigGfxInfo.BorderWdth && ClickRadius >= Cicle_radius - FigGfxInfo.BorderWdth ) {
		// checks if the user's Click Radius is on the outline of the circle
		return 1;
	}return 0;
}
void CCircle::PrintInfo(Output* pOut)
{
	// raduis of circle 
	int Cicle_radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	Point centre;
	centre.x = (P1.x - P2.x);   centre.y = (P1.y - P2.y);

	// concatination to print one sting contaion all data of figure
		// to_string ()  is a function that cast int to strting

	string printed = " Figure is Circle         Figure id :" + to_string(id) + "         Radius : " + to_string(Cicle_radius)
		+ "       Centre : (" + to_string(centre.x) + "," + to_string(centre.y) + ")";
	pOut->PrintMessage(printed);


}
color CCircle::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
bool CCircle::is_filled()
{
	return FigGfxInfo.isFilled;
}
CCircle::~CCircle()
{
	numofshapes--;
}
void CCircle::resetnumoffig()
{
	numofshapes = 0;
}