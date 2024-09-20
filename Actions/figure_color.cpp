#include "figure_color.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/playSound.h"
#include <cstdlib> 

figure_color::figure_color(ApplicationManager* pApp):Action(pApp)
{
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetOutput()->CreatePlayToolBar();
	pManager->CopyDeletedFigToFiglist();
	pManager->UpdateInterface();
}
void figure_color::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	
}
void figure_color::manage_by_color(color c , int n)
{
	string s;
	s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
	pManager->GetOutput()->PrintMessage(s);
	while (n && (p.y>50))
	{
		ReadActionParameters();
		selected_fig = pManager->GetFigure(p.x, p.y);
		if (selected_fig)
		{
			if (selected_fig->get_fillcolor() == c)
			{
				pManager->DeleteFunctionForPlayMood(selected_fig);
				correct++;
				playSound(pManager, CorrectChoose);
				s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
				pManager->GetOutput()->PrintMessage(s);
				n--;
			}
			else
			{
				pManager->DeleteFunctionForPlayMood(selected_fig);
				incorrect++;
				playSound(pManager, WrongChoose);
				s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
				pManager->GetOutput()->PrintMessage(s);
			}
		}
	}
}
void figure_color::Execute(bool b)
{
	string s;
	 by_color = colors(rand() % 6);
	int n;//num of figure should selected_by_colors
	switch (by_color)
	{
	case black:
		n=pManager->get_numofcolor(BLACK);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of black figures click to start");
			ReadActionParameters();
			manage_by_color(BLACK, n);
		}
		else
			Execute(b);
		break;
	case red:
		n = pManager->get_numofcolor(RED);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of red figures click to start");
			ReadActionParameters();
			manage_by_color(RED, n);
		}
		else
			Execute(b);
		break;
	case blue:
		n = pManager->get_numofcolor(BLUE);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of blue figures click to start");
			ReadActionParameters();
			manage_by_color(BLUE, n);
		}
		else
			Execute(b);
		break;
	case green:
		n = pManager->get_numofcolor(GREEN);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of green figures click to start");
			ReadActionParameters();
			manage_by_color(GREEN, n);
		}
		else
			Execute(b);
		break;
	case yellow:
		n = pManager->get_numofcolor(YELLOW);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of yellow figures click to start");
			ReadActionParameters();
			manage_by_color(YELLOW, n);
		}
		else
			Execute(b);
		break;
	case orange:
		n = pManager->get_numofcolor(ORANGE);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of orange figures click to start");
			ReadActionParameters();
			manage_by_color(ORANGE, n);
		}
		else
			Execute(b);
		break;
	default:
		break;
	}
	if (correct > incorrect)
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