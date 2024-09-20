#include "Output.h"
#include <windows.h>
#include <mmsystem.h>
#include "../Actions/playSound.h"
#include "../DEFS.h"
#pragma comment(lib, "winmm.lib") 



Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;


	UI.width = 1250;
	UI.height = 650;
	UI.wx = 10;
	UI.wy = 10;



	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 45;
	UI.MiniColorWidth = UI.MenuItemWidth - 30;
	UI.MiniColorHeight = UI.ToolBarHeight - 30;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GRAY;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = GREY;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);

	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	createIntro();

	CreateStatusBar();

	ClearDrawArea();
	//Change the title
	//pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}



Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::DrawImage(const string path, int x, int y, int Iwidth, int Iheight) const
{
	pWind->DrawImage(path, x, y, Iwidth, Iheight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	color cColor = getCrntDrawColor(); // Saves the users current color 
	int PenSize = getCrntPenWidth();	// and brush width
	// Set the brush and pen white so we can clear the background
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);

	// Draw a rectangle that covers the old draw mode bar
	pWind->DrawRectangle(0, 0, pWind->GetWidth(), UI.ToolBarHeight);
	pWind->SetPen(cColor, PenSize);
	pWind->SetBrush(cColor);
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_TRIA] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_SQUA] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\deleteObject.jpg";
	MenuItemImages[ITM_BRUSH] = "images\\MenuItems\\Brush.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_START_REC] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_PLAY_REC] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_STOP_REC] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\export.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\import.jpg";
	MenuItemImages[PLAY_MODE] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[CLEAR_CANVAS] = "images\\MenuItems\\clearCanvas.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
	{
		//pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 5);


		if (i == ITM_BLACK)
		{
			int k = 0;
			for (int j = ITM_BLACK; j < ITM_GREEN; j++)
			{
				pWind->DrawImage(MenuItemImages[j], ((j)*UI.MenuItemWidth - k * 22), 1, UI.MiniColorWidth, UI.MiniColorHeight);
				k++;
				i = j;
			}
			k = 0;
			for (int j = ITM_GREEN; j <= ITM_ORANGE; j++)
			{
				pWind->DrawImage(MenuItemImages[j], ((j - 3) * UI.MenuItemWidth - k * 22), 25, UI.MiniColorWidth, UI.MiniColorHeight);
				k++;
				i = j;
			}



		}
		else
			if (i > ITM_ORANGE)                         /// condition to shift back 
				pWind->DrawImage(MenuItemImages[i], (i - 4) * UI.MenuItemWidth, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 5);
			else
				pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 5);

	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	color cColor = getCrntDrawColor(); // Saves the users current color 
	int PenSize = getCrntPenWidth();	// and brush width
	// Set the brush and pen white so we can clear the background
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);

	// Draw a rectangle that covers the old draw mode bar
	pWind->DrawRectangle(0, 0, pWind->GetWidth(), UI.ToolBarHeight);

	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[DRAW_MODE] = "images\\MenuItems\\drawingMode.jpg";
	MenuItemImages[byColor] = "images\\MenuItems\\color.jpg";
	MenuItemImages[byShape] = "images\\MenuItems\\shape.jpg";
	MenuItemImages[byColorShape] = "images\\MenuItems\\shapeAndColor.jpg";
	MenuItemImages[ITM_EXIT_playMode] = "images\\MenuItems\\exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 5);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->SetPen(cColor, PenSize);
	pWind->SetBrush(cColor);
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
void Output::createIntro()
{

	pWind->DrawImage("images\\MenuItems\\PaintLogo.jpg", 0, 0, UI.width, UI.height - UI.StatusBarHeight);
	Names();
	PlaySound(".\\sounds\\Welcome Sound.wav", NULL, SND_SYNC | SND_FILENAME);

	Sleep(100);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 25);
	pWind->SetFont(17, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

void Output::SetDraColor(color c)
{

	UI.DrawColor = c;
}
void Output::SetFillColor(color c)
{
	UI.FillColor = c;
}







//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}
void Output::DrawCirc(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const  //Draw a Circle
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y)), style);
}
void Output::Drawrtriangle(int x1, int y1, int x2, int y2, int x3, int y3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(x1, y1, x2, y2, x3, y3, style);

}
void Output::Drawhexagon(const int* xcoordinates, const int* ycoordinates, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(xcoordinates, ycoordinates, 6, style);

}
void Output::Names()
{
   
	pWind->SetPen(BLACK, 20);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5)-10, " Created By :    Salah         Hussin       Noser        Esraa");

}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

