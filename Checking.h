#pragma once
#include "stdafx.h"

// The class Cheking needed to use his methods of check in other source files like an example of this class and btw all this methods are solving the same task
class Cheсking
{
public:
	int checkmat(int m, int n);

	/*cheking row for mathces*/
	int checkrow(int m, int n);

	/*cheking row for mathces*/
	int checkcolumn(int m, int n);

	/*function to check consistency of an element*/
	int check(int m, int n);
	
	/*cheking the number has been already fixed in the table*/
	int isfixed(int count, int m, int n);
};
