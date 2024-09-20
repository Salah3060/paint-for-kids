#include "CFigure.h"

bool CFigure::NewIsFilled = false;
int CFigure::ID = 1;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	if (NewIsFilled)
		FigGfxInfo.isFilled = true;
	Selected = false;
}


CFigure::CFigure() {}

void CFigure::SetSelected(bool s)
{
	Selected = s;

}
void CFigure::IsAllNewFilled(bool s)
{
	NewIsFilled = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}
void CFigure::ResetID()
{
	ID = 1;
}


void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}
void CFigure::clearColor()
{
	UI.FillColor = UI.BkGrndColor;         //Clearing color before playing recordings


}
void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;

}
bool CFigure::is_filled()
{
	return true;
}

ostream& operator<<(ostream& op, const Point& p) {
	op << p.x << " " << p.y;
	return op;
}


ostream& operator << (ostream& op, const GfxInfo& gfx) {
	op << gfx.DrawClr << " " << gfx.FillClr << " " << gfx.isFilled << " " << gfx.BorderWdth;
	return op;
}

Point operator+(const Point& p1, const Point& p2) {
	return { p1.x + p2.x,p1.y + p2.y };
};
Point operator/(const Point& p1, int i) {
	return { p1.x / i,p1.y / i };
};
Point operator-(const Point& p1, const Point& p2) {
	return { p1.x - p2.x,p1.y - p2.y };
}

;


color CFigure::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
void CFigure::decrementnumofshapes()
{

}
void CFigure::resetnumoffig()
{

}