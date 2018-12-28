#pragma once
#include "stdafx.h"

//class with function needed to solve sudoku	
class Solve
{
public:
	/*function to solve sudoku*/
	int solve();
	/*helful methods needed for solve()*/
	int mainallot();

	int backadjust();
};

//class with fucntion needed to generate sudoku
class Generate
{
public:
	/*function to solve sudoku*/
	void generate();
	/*helful methods needed for generate()*/
	void gen();

	void allot();
};
