#include "figure_type.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
#include <cstdlib> 
#include "Actions/DeleteAction.h"
#include "Actions/playSound.h"
figure_type::figure_type(ApplicationManager* pApp) :Action(pApp)
{
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetOutput()->CreatePlayToolBar();
	pManager->CopyDeletedFigToFiglist();
	pManager->UpdateInterface();
}
void figure_type::ReadActionParameters()
{

	pManager->GetInput()->GetPointClicked(p.x, p.y);

}
void figure_type::manage_byfigure()
{
	//managing playing by figure
	string s;
	if (selected_fig) //check if pick correct and increment counter
	{
		pManager->DeleteFunctionForPlayMood(selected_fig);
		correct++;
		playSound(pManager, CorrectChoose);
		s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		numoffigure--;
	}
	else //check if pick incorrect and increment counter
	{
		pManager->DeleteFunctionForPlayMood(pManager->GetFigure(p.x , p.y));
		incorrect++;
		playSound(pManager, WrongChoose);
		s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
	}

}
void figure_type::Execute(bool b)
{

	by_fig = figures(rand() % 5); //get random shape
	switch (by_fig) //check any will selected by child and return its number
	{
	case squr:
		numoffigure = CSquare::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of squares click to start");
		break;
	case rect:
		numoffigure = CRectangle::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of rectangles click to start");
		break;
	case circ:
		numoffigure = CCircle::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of circles click to start");
		break;
	case tria:
		numoffigure = CTriangle::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of triangles click to start");
		break;
	case hexa:
		numoffigure = CHexa::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of hexagines click to start");
		break;
	default:
		break;
	}
	
	if (numoffigure == 0)
		Execute( b);
	else
	{
		pManager->GetInput()->GetPointClicked(p.x, p.y);
		string s = "correct picks=" + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		while (numoffigure && (p.y > 50))
		{
			ReadActionParameters();
			if (pManager->GetFigure(p.x, p.y)) //detect what shape choosen
			{
				switch (by_fig)
				{
				case squr:
					selected_fig = dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case rect:
					selected_fig = dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case circ:
					selected_fig = dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case tria:
					selected_fig = dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case hexa:
					selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				default:
					break;
				}
			}
		}
		if (correct > incorrect) // show result
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  BRAVOOO";
			playSound(pManager, WinSound);
			pManager->GetOutput()->PrintMessage(s);
		}
		else if (incorrect > correct)
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  not good, try again";
			playSound(pManager, GameOver);
			pManager->GetOutput()->PrintMessage(s);
		}
		else
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  not bad";
			pManager->GetOutput()->PrintMessage(s);
		}
	}
}

