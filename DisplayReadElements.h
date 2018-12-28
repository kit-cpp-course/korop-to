#pragma once
#include "stdafx.h"

//Class with function needed to read elements
class Read
{
public:
	/*function to read elements from keyboard*/
	void readvalues();

	//helpful methods needed for readvalues
	void readrow();

	void readcolumn();

	void readscan();

};

//class with function needed to display the table of sudoku
class Display
{
public:
	/*function to display sudoku*/
	void display();

};

/*helpful function needed to work with gotoxy*/
void gotoxy(int xpos, int ypos);
