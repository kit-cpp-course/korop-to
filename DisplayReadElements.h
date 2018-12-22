#pragma once
#include "stdafx.h"


class DisplayAndRead
{
public:
	
	/*FUNTION TO READ ELEMENTS*/
	void readvalues();

	/*HELPFUL FUNCTION NEEDED TO WORK WITH GOTOXY*/
	void gotoxy(int xpos, int ypos);

	/*FUNCTION TO DISPLAY SUDOKU*/
	static void display();
	
};